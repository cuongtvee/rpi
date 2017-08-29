/*
-- Company: Trenz Electronic GmbH
-- Engineer: Oleksandr Kiyenko
 */
#include <stdio.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "sensor_config.h"

#define CAMERA_IIC_ADDRESS      0x36

#define CS_CMMN_CHIP_ID_H       0x300A
#define CS_CMMN_CHIP_ID_L       0x300B

unsigned char i2c_reg_read(int dev_file, unsigned char dev_addr, unsigned short reg_addr)
{
    unsigned char inbuf[2];
    unsigned char outbuf[2];
    struct i2c_rdwr_ioctl_data packets;
    struct i2c_msg messages[2];

    /*
    * In order to read a register, we first do a "dummy write" by writing
    * 0 bytes to the register we want to read from.  This is similar to
    * the packet in set_i2c_register, except it's 1 byte rather than 2.
    */
    outbuf[0] = reg_addr >> 8;
    outbuf[1] = reg_addr & 0xFF;
    messages[0].addr  = dev_addr;
    messages[0].flags = 0;
    messages[0].len   = sizeof(outbuf);
    messages[0].buf   = &outbuf;
    /* The data will get returned in this structure */
    messages[1].addr  = dev_addr;
    messages[1].flags = I2C_M_RD/* | I2C_M_NOSTART*/;
    messages[1].len   = sizeof(inbuf);
    messages[1].buf   = inbuf;

    /* Send the request to the kernel and get the result back */
    packets.msgs      = messages;
    packets.nmsgs    = 2;
    if(ioctl(dev_file, I2C_RDWR, &packets) < 0) {
        perror("Unable to send data");
        return 1;
    }

    return inbuf[0];
}

int i2c_reg_write(int dev_file, unsigned char dev_addr, unsigned short reg_addr, unsigned char reg_data)
{
    unsigned char outbuf[3];
    struct i2c_rdwr_ioctl_data packets;
    struct i2c_msg messages[1];

    messages[0].addr  = dev_addr;
    messages[0].flags = 0;
    messages[0].len   = sizeof(outbuf);
    messages[0].buf   = &outbuf;
    /* The first byte indicates which register we'll write */
    outbuf[0] = reg_addr >> 8;
    outbuf[1] = reg_addr & 0xFF;
    outbuf[2] = reg_data;
    /* Transfer the i2c packets to the kernel and verify it worked */
    packets.msgs  = messages;
    packets.nmsgs = 1;
    if(ioctl(dev_file, I2C_RDWR, &packets) < 0) {
        perror("Unable to send data");
        return 1;
    }

    return 0;
}

static void i2c_set_write(int dev_file, unsigned char dev_addr, struct sensor_cmd *set)
{
    int i;
    for(i=0; set[i].reg != 0; i++){
        i2c_reg_write(dev_file, CAMERA_IIC_ADDRESS, set[i].reg, set[i].val);
    }
}

int main(int argc, char *argv[])
{
    int i2c_file;

    printf("Raspberry Pi Camera Init\n");
    if(argc < 2){
        printf("%s /dev/i2c-X [mode]\n",argv[0]);
        exit(1);
    }

    if ((i2c_file = open(argv[1], O_RDWR)) < 0) {
        perror("Unable to open i2c control file");
        exit(1);
    }

    if((i2c_reg_read(i2c_file, CAMERA_IIC_ADDRESS, CS_CMMN_CHIP_ID_H) != 0x56) || (i2c_reg_read(i2c_file, CAMERA_IIC_ADDRESS, CS_CMMN_CHIP_ID_L) != 0x47)){
        perror("Camera not found");
        exit(1);
    }

    i2c_reg_write(i2c_file, CAMERA_IIC_ADDRESS, 0x0100, 0x00);          // Disable
    i2c_reg_write(i2c_file, CAMERA_IIC_ADDRESS, 0x0103, 0x01);          // Reset
    usleep(1);                                                          // Wait
    i2c_reg_write(i2c_file, CAMERA_IIC_ADDRESS, 0x0103, 0x00);          // Reset
    usleep(10 * 1000);                                                  // Wait
    i2c_set_write(i2c_file, CAMERA_IIC_ADDRESS, sensor_common_10bit);   // Load common configuration
//    i2c_set_write(i2c_file, CAMERA_IIC_ADDRESS, sensor_common_test);   // Load common configuration
    i2c_set_write(i2c_file, CAMERA_IIC_ADDRESS, sensor_1296_968_30);    // Load specific configuration
//    i2c_set_write(i2c_file, CAMERA_IIC_ADDRESS, sensor_1280_720_30);    // Load specific configuration
    i2c_reg_write(i2c_file, CAMERA_IIC_ADDRESS, 0x0100, 0x01);          // Enable
    printf("Camera init complete.\n");
    close(i2c_file);
	return 0;
}


