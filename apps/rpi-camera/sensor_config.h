
#ifndef SENSOR_CONFIG_H_
#define SENSOR_CONFIG_H_

//-----------------------------------------------------------------------------------------

// atomar register element
struct sensor_cmd {
    unsigned short reg;
    unsigned char   val;
};

//-----------------------------------------------------------------------------------------

static struct sensor_cmd sensor_common_10bit[] = {
    { 0x3034, 0x1A },   // 10 bit mode
//  { 0x3034, 0x10 },   // 8 bit mode
    { 0x503D, 0x00 },   // Test Pattern
    { 0x3035, 0x21 },   // CLK DIV
    { 0x3036, 0x46 },   // PLL MULT
    { 0x303c, 0x11 },   // PLLS CP
    { 0x3106, 0xf5 },   // PLL DIV
    { 0x3821, 0x07 },   // TIMING TC
    { 0x3820, 0x41 },   // TIMING TC
    { 0x3827, 0xec },
    { 0x370c, 0x0f },
    { 0x3612, 0x59 },
    { 0x3503, 0x00 }, // AEC/AGC
    { 0x5000, 0x89 }, // Lens Correction
    { 0x5001, 0x01 }, // AWB
    { 0x5002, 0x41 }, // AWB GAIN, OPT, WIN
    { 0x5003, 0x0A }, // BIN
    { 0x5a00, 0x08 },
    { 0x3000, 0x00 },
    { 0x3001, 0x00 },
    { 0x3002, 0x00 },
    { 0x3016, 0x08 },
    { 0x3017, 0xe0 },
    { 0x3018, 0x44 },
    { 0x301c, 0xf8 },
    { 0x301d, 0xf0 },
    { 0x3a18, 0x00 },
    { 0x3a19, 0xf8 },
    { 0x3c01, 0x80 }, // 50/60HZ Detection
    { 0x3b07, 0x0c },
    { 0x380c, 0x07 },
    { 0x380d, 0x68 },
    { 0x380e, 0x03 },
    { 0x380f, 0xd8 },
    { 0x3814, 0x31 },
    { 0x3815, 0x31 },
    { 0x3708, 0x64 },
    { 0x3709, 0x52 },
    { 0x3630, 0x2e },
    { 0x3632, 0xe2 },
    { 0x3633, 0x23 },
    { 0x3634, 0x44 },
    { 0x3636, 0x06 },
    { 0x3620, 0x65 },  // V BINNING
    { 0x3621, 0xe1 },  // H BINNING
    { 0x3600, 0x37 },
    { 0x3704, 0xa0 },
    { 0x3703, 0x5a },
    { 0x3715, 0x78 },
    { 0x3717, 0x01 },
    { 0x3731, 0x02 },
    { 0x370b, 0x60 },
    { 0x3705, 0x1a },
    { 0x3f05, 0x02 },
    { 0x3f06, 0x10 },
    { 0x3f01, 0x0a },
    { 0x3a08, 0x01 },
    { 0x3a09, 0x27 },
    { 0x3a0a, 0x00 },
    { 0x3a0b, 0xf6 },
    { 0x3a0d, 0x04 },
    { 0x3a0e, 0x03 },
    { 0x3a0f, 0x58 },
    { 0x3a10, 0x50 },
    { 0x3a1b, 0x58 },
    { 0x3a1e, 0x50 },
    { 0x3a11, 0x60 },
    { 0x3a1f, 0x28 },
    { 0x4001, 0x02 },
    { 0x4004, 0x02 },
    { 0x4000, 0x09 },
    { 0x4837, 0x24 },
    { 0x4050, 0x6e },
    { 0x4051, 0x8f },
    { 0x0000, 0x00 },
};

//-----------------------------------------------------------------------------------------

static struct sensor_cmd sensor_common_test[] = {
    { 0x3034, 0x1A },   // 10 bit mode
    { 0x503D, 0x80 },
//  { 0x3035, 0x21 },
//  { 0x3036, 0x46 },
//  { 0x303c, 0x11 },
    { 0x3106, 0xf5 },
//  { 0x3821, 0x07 },
//  { 0x3820, 0x41 },
    { 0x3827, 0xec },
    { 0x370c, 0x0f },
//  { 0x3612, 0x59 },
//  { 0x3618, 0x00 },
    { 0x5000, 0x06 },
    { 0x5001, 0x00 },
    { 0x5002, 0x40 },
    { 0x5003, 0x08 },
    { 0x5a00, 0x08 },
    { 0x3000, 0x00 },
    { 0x3001, 0x00 },
    { 0x3002, 0x00 },
    { 0x3016, 0x08 },
    { 0x3017, 0xe0 },
    { 0x3018, 0x44 },
    { 0x301c, 0xf8 },
    { 0x301d, 0xf0 },
    { 0x3a18, 0x00 },
    { 0x3a19, 0xf8 },
    { 0x3c01, 0x80 },
    { 0x3b07, 0x0c },
//  { 0x380c, 0x07 },
//  { 0x380d, 0x68 },
//  { 0x380e, 0x03 },
//  { 0x380f, 0xd8 },
//  { 0x3814, 0x31 },
//  { 0x3815, 0x31 },
//  { 0x3708, 0x64 },
//  { 0x3709, 0x52 },
    { 0x3630, 0x2e },
    { 0x3632, 0xe2 },
    { 0x3633, 0x23 },
    { 0x3634, 0x44 },
    { 0x3636, 0x06 },
    { 0x3620, 0x64 },
    { 0x3621, 0xe0 },
    { 0x3600, 0x37 },
    { 0x3704, 0xa0 },
    { 0x3703, 0x5a },
    { 0x3715, 0x78 },
    { 0x3717, 0x01 },
    { 0x3731, 0x02 },
    { 0x370b, 0x60 },
    { 0x3705, 0x1a },
    { 0x3f05, 0x02 },
    { 0x3f06, 0x10 },
    { 0x3f01, 0x0a },
//  { 0x3a08, 0x01 },
//  { 0x3a09, 0x27 },
//  { 0x3a0a, 0x00 },
//  { 0x3a0b, 0xf6 },
//  { 0x3a0d, 0x04 },
//  { 0x3a0e, 0x03 },
    { 0x3a0f, 0x58 },
    { 0x3a10, 0x50 },
    { 0x3a1b, 0x58 },
    { 0x3a1e, 0x50 },
    { 0x3a11, 0x60 },
    { 0x3a1f, 0x28 },
    { 0x4001, 0x02 },
//  { 0x4004, 0x02 },
    { 0x4000, 0x09 },
//  { 0x4837, 0x24 },
    { 0x4050, 0x6e },
    { 0x4051, 0x8f },
    { 0x0000, 0x00 },
};

//-----------------------------------------------------------------------------------------

/* 2592 x 1944 @ 15 fps */
    /*
     * MIPI Link   : 425.000 Mbps
     * Pixel clock : 85.000 MHz
     * Timing zone : 2752 x 1974
     * FPS         : 15.6
    */
static struct sensor_cmd sensor_2592_1944_15[] = {
    { 0x3035, 0x21 },
    { 0x3036, 0x66 },
    { 0x303c, 0x11 },
    { 0x3821, 0x06 },
    { 0x3820, 0x00 },
    { 0x3612, 0x5b },
    { 0x3618, 0x04 },
    { 0x380c, 0x0a },
    { 0x380d, 0xc0 },
    { 0x380e, 0x07 },
    { 0x380f, 0xb6 },
    { 0x3814, 0x11 },
    { 0x3815, 0x11 },
    { 0x3708, 0x64 },
    { 0x3709, 0x12 },
    { 0x3808, 0x0a },
    { 0x3809, 0x20 },
    { 0x380a, 0x07 },
    { 0x380b, 0x98 },
    { 0x3800, 0x00 },
    { 0x3801, 0x0c },
    { 0x3802, 0x00 },
    { 0x3803, 0x02 },
    { 0x3804, 0x0a },
    { 0x3805, 0x33 },
    { 0x3806, 0x07 },
    { 0x3807, 0xa1 },
    { 0x3a08, 0x01 },
    { 0x3a09, 0x28 },
    { 0x3a0a, 0x00 },
    { 0x3a0b, 0xf6 },
    { 0x3a0d, 0x07 },
    { 0x3a0e, 0x06 },
    { 0x4004, 0x04 },
    { 0x4837, 0x19 },
    { 0x0000, 0x00 },
};

//-----------------------------------------------------------------------------------------

/* 1936 x 1088 @ 30 fps */
    /*
     * MIPI Link   : 416.667 Mbps
     * Pixel clock : 83.333 MHz
     * Timing zone : 2416 x 1104
     * FPS         : 31.2
     */
static struct sensor_cmd sensor_1936_1088_30[] = {
    { 0x3035, 0x21 },
    { 0x3036, 0x64 },
    { 0x303c, 0x11 },
    { 0x3821, 0x06 },
    { 0x3820, 0x00 },
    { 0x3612, 0x5b },
    { 0x3618, 0x04 },
    { 0x380c, 0x09 },
    { 0x380d, 0x70 },
    { 0x380e, 0x04 },
    { 0x380f, 0x50 },
    { 0x3814, 0x11 },
    { 0x3815, 0x11 },
    { 0x3708, 0x64 },
    { 0x3709, 0x12 },
    { 0x3808, 0x07 },
    { 0x3809, 0x90 },	/* 80 */
    { 0x380a, 0x04 },
    { 0x380b, 0x40 },	/* 38 */
    { 0x3800, 0x01 },
    { 0x3801, 0x54 },	/* 5c */
    { 0x3802, 0x01 },
    { 0x3803, 0xb0 },	/* b2 */
    { 0x3804, 0x08 },
    { 0x3805, 0xeb },	/* e3 */
    { 0x3806, 0x05 },
    { 0x3807, 0xf3 },	/* f1 */
    { 0x3a08, 0x01 },
    { 0x3a09, 0x4b },
    { 0x3a0a, 0x01 },
    { 0x3a0b, 0x13 },
    { 0x3a0d, 0x04 },
    { 0x3a0e, 0x03 },
    { 0x4004, 0x04 },
    { 0x4837, 0x19 },
    { 0x0000, 0x00 },
};

//-----------------------------------------------------------------------------------------

/* 1296 x 968 @ 30 fps */
    /*
     * MIPI Link   : 291.667 Mbps
     * Pixel clock : 58.333 MHz
     * Timing zone : 1896 x 984
     * FPS         : 31.3
     */
static struct sensor_cmd sensor_1296_968_30[] = {
    { 0x3035, 0x21 },
    { 0x3036, 0x46 },
    { 0x303c, 0x11 },
    { 0x3821, 0x07 },
    { 0x3820, 0x41 },
    { 0x3612, 0x59 },
    { 0x3618, 0x00 },
    { 0x380c, 0x07 },
    { 0x380d, 0x68 },
    { 0x380e, 0x03 },
    { 0x380f, 0xd8 },
    { 0x3814, 0x31 },
    { 0x3815, 0x31 },
    { 0x3708, 0x64 },
    { 0x3709, 0x52 },
    { 0x3808, 0x05 },
    { 0x3809, 0x10 },	/* 00 */
    { 0x380a, 0x03 },
    { 0x380b, 0xc8 },	/* c0 */
    { 0x3800, 0x00 },
    { 0x3801, 0x00 },	/* 18 */
    { 0x3802, 0x00 },
    { 0x3803, 0x08 },	/* 0e */
    { 0x3804, 0x0a },
    { 0x3805, 0x3b },	/* 27 */
    { 0x3806, 0x07 },
    { 0x3807, 0x9b },	/* 95 */
    { 0x3a08, 0x01 },
    { 0x3a09, 0x27 },
    { 0x3a0a, 0x00 },
    { 0x3a0b, 0xf6 },
    { 0x3a0d, 0x04 },
    { 0x3a0e, 0x03 },
    { 0x4004, 0x02 },
    { 0x4837, 0x24 },
    { 0x0000, 0x00 },
};

//-----------------------------------------------------------------------------------------

/* 1280 x 720 @ 30 fps */
    /*
     * MIPI Link   : 291.667 Mbps
     * Pixel clock : 58.333 MHz
     * Timing zone : 1896 x 984
     * FPS         : 31.3
     */
static struct sensor_cmd sensor_1280_720_30[] = {
  { 0x3035, 0x21 },   // *
  { 0x3036, 0x46 },   // * PLL multiplier
  { 0x303c, 0x11 },   // * PLL div
  { 0x3821, 0x07 },   // * Timing
  { 0x3820, 0x41 },   // * Timing
  { 0x3612, 0x59 },   // ?
  { 0x3618, 0x00 },   // ?
  { 0x380c, 0x07 },   // * Horisontal size [12:8] 1896
  { 0x380d, 0x68 },   // * Horisontal size [7:0]
  { 0x380e, 0x03 },   // * total vertical size [9:8]  984
  { 0x380f, 0xd8 },   // * total vertical size [7:0]
  { 0x3814, 0x31 },   // * timing x inc
  { 0x3815, 0x31 },   // * timing y inc
  { 0x3708, 0x64 },   //
  { 0x3709, 0x52 },   //
  { 0x3808, 0x05 },   //  out horisontal [11:8]   1280
  { 0x3809, 0x00 },   //  out horisontal [7:0]
  { 0x380a, 0x02 },   //  out vertical [11:8]     720
  { 0x380b, 0xd0 },   //  out vertical [7:0]
  { 0x3800, 0x00 },   //  + X start [11:8]
  { 0x3801, 0x00 },   //  + X start [7:0] /* 18 */
  { 0x3802, 0x00 },   //  + Y start [11:8]
  { 0x3803, 0x08 },   //  + Y start [7:0] /* 0e */
  { 0x3804, 0x0a },   //  + X end [11:8]
  { 0x3805, 0x3b },   //  + X end [7:0]  /* 27 */
  { 0x3806, 0x07 },   //  + Y end [11:8]
  { 0x3807, 0x9b },   //  + Y end [7:0] /* 95 */
  { 0x3a08, 0x01 },   //
  { 0x3a09, 0x27 },   //
  { 0x3a0a, 0x00 },   //
  { 0x3a0b, 0xf6 },   //
  { 0x3a0d, 0x04 },   //
  { 0x3a0e, 0x03 },   //
  { 0x4004, 0x02 },   //
  { 0x4837, 0x24 },   // * PCLK period
  { 0x0000, 0x00 },   //
};

//-----------------------------------------------------------------------------------------

static struct sensor_cmd sensor_640_480_90[] = {
    { 0x3035, 0x11 },
    { 0x3036, 0x2a },
    { 0x3821, 0x07 },
    { 0x3820, 0x41 },
    { 0x3612, 0x49 },
    { 0x3618, 0x00 },
    { 0x380c, 0x07 },
    { 0x380d, 0x30 },
    { 0x380e, 0x01 },
    { 0x380f, 0x78 },
    { 0x3814, 0x71 },
    { 0x3815, 0x31 },
    { 0x3709, 0x52 },
    { 0x3808, 0x02 },
    { 0x3809, 0x80 },
    { 0x380a, 0x01 },
    { 0x380b, 0xe8 },
    { 0x3800, 0x00 },
    { 0x3801, 0x10 },
    { 0x3802, 0x00 },
    { 0x3803, 0x00 },
    { 0x3804, 0x0a },
    { 0x3805, 0x2f },
    { 0x3806, 0x07 },
    { 0x3807, 0x9f },
    { 0x4004, 0x02 },
};

//-----------------------------------------------------------------------------------------

#endif