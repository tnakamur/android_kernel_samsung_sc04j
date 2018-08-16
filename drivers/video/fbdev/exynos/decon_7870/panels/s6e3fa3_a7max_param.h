#ifndef __S6E3FA3_A7MAX_PARAM_H__
#define __S6E3FA3_A7MAX_PARAM_H__

#include <linux/types.h>
#include <linux/kernel.h>
#include "dynamic_aid_s6e3fa3_a7max.h"

#define EXTEND_BRIGHTNESS	365
#define UI_MAX_BRIGHTNESS	255
#define UI_MIN_BRIGHTNESS	0
#define UI_DEFAULT_BRIGHTNESS	128
#define NORMAL_TEMPERATURE	25	/* 25 degrees Celsius */

#define GAMMA_CMD_CNT		ARRAY_SIZE(SEQ_GAMMA_CONDITION_SET)
#define ACL_CMD_CNT		ARRAY_SIZE(SEQ_ACL_OFF)
#define OPR_CMD_CNT		ARRAY_SIZE(SEQ_OPR_ACL_OFF)
#define ELVSS_CMD_CNT		ARRAY_SIZE(SEQ_ELVSS_SET)
#define AID_CMD_CNT		ARRAY_SIZE(SEQ_AID_SETTING)
#define HBM_CMD_CNT		ARRAY_SIZE(SEQ_HBM_OFF)
#define TSET_CMD_CNT		ARRAY_SIZE(SEQ_TSET_SETTING)

#define LDI_REG_ELVSS		0xB6
#define LDI_REG_COORDINATE	0xA1
#define LDI_REG_DATE		LDI_REG_MTP
#define LDI_REG_ID		0x04
#define LDI_REG_CHIP_ID		0xD6
#define LDI_REG_MTP		0xC8
#define LDI_REG_HBM		0xB4
#define LDI_REG_RDDPM		0x0A
#define LDI_REG_RDDSM		0x0E
#define LDI_REG_ESDERR		0xEE

/* len is read length */
#define LDI_LEN_ELVSS		(ELVSS_CMD_CNT - 1)
#define LDI_LEN_COORDINATE	4
#define LDI_LEN_DATE		7
#define LDI_LEN_ID		3
#define LDI_LEN_CHIP_ID		5
#define LDI_LEN_MTP		35
#define LDI_LEN_HBM		28
#define LDI_LEN_RDDPM		1
#define LDI_LEN_RDDSM		1
#define LDI_LEN_ESDERR		1

/* offset is position including addr, not only para */
#define LDI_OFFSET_AOR_1	1
#define LDI_OFFSET_AOR_2	2

#define LDI_OFFSET_ELVSS_1	1	/* B6h 1st Para: MPS_CON */
#define LDI_OFFSET_ELVSS_2	2	/* B6h 2nd Para: ELVSS_Dim_offset */
#define LDI_OFFSET_ELVSS_3	22	/* B6h 22nd Para: ELVSS Temp Compensation */

#define LDI_OFFSET_HBM		1
#define LDI_OFFSET_ACL		1
#define LDI_OFFSET_TSET		1

#define LDI_GPARA_DATE		40	/* 0xC8 41st Para */
#define LDI_GPARA_HBM_ELVSS	22	/* 0xB6 23th para */

struct lcd_seq_info {
	unsigned char	*cmd;
	unsigned int	len;
	unsigned int	sleep;
};

static unsigned char SEQ_SLEEP_OUT[] = {
	0x11
};

static unsigned char SEQ_SLEEP_IN[] = {
	0x10
};

static unsigned char SEQ_DISPLAY_ON[] = {
	0x29
};

static unsigned char SEQ_DISPLAY_OFF[] = {
	0x28
};

static unsigned char SEQ_TEST_KEY_ON_F0[] = {
	0xF0,
	0x5A, 0x5A
};

static unsigned char SEQ_TEST_KEY_OFF_F0[] = {
	0xF0,
	0xA5, 0xA5
};

static unsigned char SEQ_TEST_KEY_ON_FC[] = {
	0xFC,
	0x5A, 0x5A
};

static unsigned char SEQ_TEST_KEY_OFF_FC[] = {
	0xFC,
	0xA5, 0xA5
};

static unsigned char SEQ_TE_ON[] = {
	0x35,
	0x00
};

static unsigned char SEQ_PCD_SET_DET_LOW[] = {
	0xCC,
	0x5C
};

static unsigned char SEQ_ERR_FG_SETTING[] = {
	0xED,
	0x44
};

static unsigned char SEQ_AVC_SETTING_1[] = {
	0xB0,
	0x1E
};

static unsigned char SEQ_AVC_SETTING_2[] = {
	0xFD,
	0xA8
};

static unsigned char SEQ_GAMMA_CONDITION_SET[] = {
	0xCA,
	0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x00, 0x00, 0x00, 0x00, 0x00
};

static unsigned char SEQ_AID_SETTING[] = {
	0xB2,
	0x00, 0x10
};

static unsigned char SEQ_ELVSS_SET[] = {
	0xB6,
	0xBC,	/* B6h 1st Para: MPS_CON */
	0x04,	/* B6h 2nd Para: ELVSS_Dim_offset */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00,
	0x00,	/* B6h 22nd Para: ELVSS Temp Compensation */
	0x00	/* B6h 23rd Para: OTP for B6h 22nd Para of HBM Interpolation */
};

static unsigned char SEQ_GAMMA_UPDATE[] = {
	0xF7,
	0x03
};

static unsigned char SEQ_HBM_OFF[] = {
	0x53,
	0x00
};

static unsigned char SEQ_HBM_ON[] = {
	0x53,
	0xC0
};

static unsigned char SEQ_OPR_ACL_OFF[] = {
	0xB5,
	0x40	/* 16 Frame Avg. at ACL Off */
};

static unsigned char SEQ_OPR_ACL_ON[] = {
	0xB5,
	0x50	/* 32 Frame Avg. at ACL On */
};

static unsigned char SEQ_ACL_OFF[] = {
	0x55,
	0x00
};

static unsigned char SEQ_ACL_ON[] = {
	0x55,
	0x02	/* 0x02 : ACL 8% (Default) */
};

static unsigned char SEQ_TSET_SETTING[] = {
	0xB8,
	0x19	/* (ex) 25 degree : 0x19 */
};

enum {
	ACL_STATUS_0P,
	ACL_STATUS_8P,
	ACL_STATUS_MAX
};

enum {
	OPR_STATUS_ACL_OFF,
	OPR_STATUS_ACL_ON,
	OPR_STATUS_MAX
};

enum {
	CAPS_OFF,
	CAPS_ON,
	CAPS_MAX
};

enum {
	TEMP_ABOVE_MINUS_00_DEGREE,	/* T > 0 */
	TEMP_ABOVE_MINUS_15_DEGREE,	/* -15 < T <= 0 */
	TEMP_BELOW_MINUS_15_DEGREE,	/* T <= -15 */
	TEMP_MAX
};

enum {
	HBM_STATUS_OFF,
	HBM_STATUS_ON,
	HBM_STATUS_MAX
};

static unsigned char *HBM_TABLE[HBM_STATUS_MAX] = {SEQ_HBM_OFF, SEQ_HBM_ON};
static unsigned char *ACL_TABLE[ACL_STATUS_MAX] = {SEQ_ACL_OFF, SEQ_ACL_ON};
static unsigned char *OPR_TABLE[OPR_STATUS_MAX] = {SEQ_OPR_ACL_OFF, SEQ_OPR_ACL_ON};

static unsigned char elvss_mpscon_offset_data[IBRIGHTNESS_HBM_MAX][3] = {
	[IBRIGHTNESS_002NIT] = {0xB6, 0xAC, 0x0A},
	[IBRIGHTNESS_003NIT] = {0xB6, 0xAC, 0x0A},
	[IBRIGHTNESS_004NIT] = {0xB6, 0xAC, 0x0A},
	[IBRIGHTNESS_005NIT] = {0xB6, 0xAC, 0x0A},
	[IBRIGHTNESS_006NIT] = {0xB6, 0xAC, 0x0B},
	[IBRIGHTNESS_007NIT] = {0xB6, 0xAC, 0x0C},
	[IBRIGHTNESS_008NIT] = {0xB6, 0xAC, 0x0D},
	[IBRIGHTNESS_009NIT] = {0xB6, 0xAC, 0x0E},
	[IBRIGHTNESS_010NIT] = {0xB6, 0xAC, 0x0F},
	[IBRIGHTNESS_011NIT] = {0xB6, 0xAC, 0x10},
	[IBRIGHTNESS_012NIT] = {0xB6, 0xAC, 0x11},
	[IBRIGHTNESS_013NIT] = {0xB6, 0xAC, 0x12},
	[IBRIGHTNESS_014NIT] = {0xB6, 0xAC, 0x13},
	[IBRIGHTNESS_015NIT] = {0xB6, 0xAC, 0x14},
	[IBRIGHTNESS_016NIT] = {0xB6, 0xAC, 0x14},
	[IBRIGHTNESS_017NIT] = {0xB6, 0xAC, 0x14},
	[IBRIGHTNESS_019NIT] = {0xB6, 0xAC, 0x14},
	[IBRIGHTNESS_020NIT] = {0xB6, 0xAC, 0x14},
	[IBRIGHTNESS_021NIT] = {0xB6, 0xAC, 0x14},
	[IBRIGHTNESS_022NIT] = {0xB6, 0xAC, 0x14},
	[IBRIGHTNESS_024NIT] = {0xB6, 0xAC, 0x14},
	[IBRIGHTNESS_025NIT] = {0xB6, 0xAC, 0x14},
	[IBRIGHTNESS_027NIT] = {0xB6, 0xAC, 0x14},
	[IBRIGHTNESS_029NIT] = {0xB6, 0xAC, 0x14},
	[IBRIGHTNESS_030NIT] = {0xB6, 0xAC, 0x14},
	[IBRIGHTNESS_032NIT] = {0xB6, 0xAC, 0x14},
	[IBRIGHTNESS_034NIT] = {0xB6, 0xAC, 0x14},
	[IBRIGHTNESS_037NIT] = {0xB6, 0xAC, 0x14},
	[IBRIGHTNESS_039NIT] = {0xB6, 0xAC, 0x14},
	[IBRIGHTNESS_041NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_044NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_047NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_050NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_053NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_056NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_060NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_064NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_068NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_072NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_077NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_082NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_087NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_093NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_098NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_105NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_111NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_119NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_126NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_134NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_143NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_152NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_162NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_172NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_183NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_195NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_207NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_220NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_234NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_249NIT] = {0xB6, 0xBC, 0x13},
	[IBRIGHTNESS_265NIT] = {0xB6, 0xBC, 0x12},
	[IBRIGHTNESS_282NIT] = {0xB6, 0xBC, 0x11},
	[IBRIGHTNESS_300NIT] = {0xB6, 0xBC, 0x10},
	[IBRIGHTNESS_316NIT] = {0xB6, 0xBC, 0x0F},
	[IBRIGHTNESS_333NIT] = {0xB6, 0xBC, 0x0E},
	[IBRIGHTNESS_350NIT] = {0xB6, 0xBC, 0x0D},
	[IBRIGHTNESS_357NIT] = {0xB6, 0xBC, 0x0C},
	[IBRIGHTNESS_365NIT] = {0xB6, 0xBC, 0x0C},
	[IBRIGHTNESS_372NIT] = {0xB6, 0xBC, 0x0C},
	[IBRIGHTNESS_380NIT] = {0xB6, 0xBC, 0x0C},
	[IBRIGHTNESS_387NIT] = {0xB6, 0xBC, 0x0C},
	[IBRIGHTNESS_395NIT] = {0xB6, 0xBC, 0x0B},
	[IBRIGHTNESS_403NIT] = {0xB6, 0xBC, 0x0B},
	[IBRIGHTNESS_412NIT] = {0xB6, 0xBC, 0x0A},
	[IBRIGHTNESS_420NIT] = {0xB6, 0xBC, 0x0A},
	[IBRIGHTNESS_465NIT] = {0xB6, 0xBC, 0x11},
	[IBRIGHTNESS_488NIT] = {0xB6, 0xBC, 0x10},
	[IBRIGHTNESS_510NIT] = {0xB6, 0xBC, 0x0F},
	[IBRIGHTNESS_533NIT] = {0xB6, 0xBC, 0x0E},
	[IBRIGHTNESS_555NIT] = {0xB6, 0xBC, 0x0C},
	[IBRIGHTNESS_578NIT] = {0xB6, 0xBC, 0x0B},
	[IBRIGHTNESS_600NIT] = {0xB6, 0xBC, 0x0A}
};

struct elvss_otp_info {
	unsigned int	nit;
	int not_otp[TEMP_MAX];
};

struct elvss_otp_info elvss_otp_data[IBRIGHTNESS_MAX] = {
	[IBRIGHTNESS_002NIT] = {2,	{0x12, 0x1C, 0x1F}},
	[IBRIGHTNESS_003NIT] = {3,	{0x13, 0x1C, 0x1F}},
	[IBRIGHTNESS_004NIT] = {4,	{0x14, 0x1C, 0x1F}},
	[IBRIGHTNESS_005NIT] = {5,	{0x15, 0x1C, 0x1F}},
	[IBRIGHTNESS_006NIT] = {6,	{0x15, 0x1B, 0x1E}},
	[IBRIGHTNESS_007NIT] = {7,	{0x15, 0x1B, 0x1D}},
	[IBRIGHTNESS_008NIT] = {8,	{0x15, 0x1A, 0x1C}},
	[IBRIGHTNESS_009NIT] = {9,	{0x15, 0x19, 0x1B}},
	[IBRIGHTNESS_010NIT] = {10,	{0x15, 0x18, 0x1A}},
	[IBRIGHTNESS_011NIT] = {11,	{0x15, 0x18, 0x19}},
	[IBRIGHTNESS_012NIT] = {12,	{0x15, 0x17, 0x18}},
	[IBRIGHTNESS_013NIT] = {13,	{0x15, 0x16, 0x17}},
	[IBRIGHTNESS_014NIT] = {14,	{0x15, 0x15, 0x16}},
};

static unsigned char AOR_TABLE[IBRIGHTNESS_HBM_MAX][AID_CMD_CNT] = {
	{0xB2, 0x70, 0x77},
	{0xB2, 0x70, 0x68},
	{0xB2, 0x70, 0x58},
	{0xB2, 0x70, 0x52},
	{0xB2, 0x70, 0x43},
	{0xB2, 0x70, 0x34},
	{0xB2, 0x70, 0x24},
	{0xB2, 0x70, 0x15},
	{0xB2, 0x70, 0x05},
	{0xB2, 0x60, 0xF5},
	{0xB2, 0x60, 0xE5},
	{0xB2, 0x60, 0xD5},
	{0xB2, 0x60, 0xC5},
	{0xB2, 0x60, 0xB4},
	{0xB2, 0x60, 0xA5},
	{0xB2, 0x60, 0x95},
	{0xB2, 0x60, 0x75},
	{0xB2, 0x60, 0x66},
	{0xB2, 0x60, 0x56},
	{0xB2, 0x60, 0x46},
	{0xB2, 0x60, 0x26},
	{0xB2, 0x60, 0x17},
	{0xB2, 0x50, 0xF7},
	{0xB2, 0x50, 0xD8},
	{0xB2, 0x50, 0xC8},
	{0xB2, 0x50, 0xB2},
	{0xB2, 0x50, 0x92},
	{0xB2, 0x50, 0x62},
	{0xB2, 0x50, 0x42},
	{0xB2, 0x50, 0x22},
	{0xB2, 0x40, 0xF2},
	{0xB2, 0x40, 0xC0},
	{0xB2, 0x40, 0x89},
	{0xB2, 0x40, 0x57},
	{0xB2, 0x40, 0x26},
	{0xB2, 0x30, 0xE3},
	{0xB2, 0x30, 0xA1},
	{0xB2, 0x30, 0x56},
	{0xB2, 0x30, 0x12},
	{0xB2, 0x20, 0xD4},
	{0xB2, 0x20, 0xD4},
	{0xB2, 0x20, 0xD4},
	{0xB2, 0x20, 0xD4},
	{0xB2, 0x20, 0xD4},
	{0xB2, 0x20, 0xD4},
	{0xB2, 0x20, 0xD4},
	{0xB2, 0x20, 0xD4},
	{0xB2, 0x20, 0xD4},
	{0xB2, 0x20, 0xD4},
	{0xB2, 0x20, 0xD4},
	{0xB2, 0x20, 0xD4},
	{0xB2, 0x20, 0xD4},
	{0xB2, 0x20, 0xD4},
	{0xB2, 0x20, 0xD4},
	{0xB2, 0x20, 0x74},
	{0xB2, 0x20, 0x14},
	{0xB2, 0x10, 0xA6},
	{0xB2, 0x10, 0x33},
	{0xB2, 0x00, 0xE2},
	{0xB2, 0x00, 0xE2},
	{0xB2, 0x00, 0xE2},
	{0xB2, 0x00, 0xE2},
	{0xB2, 0x00, 0xE2},
	{0xB2, 0x00, 0xE2},
	{0xB2, 0x00, 0xE2},
	{0xB2, 0x00, 0xE2},
	{0xB2, 0x00, 0xE2},
	{0xB2, 0x00, 0xC3},
	{0xB2, 0x00, 0x93},
	{0xB2, 0x00, 0x65},
	{0xB2, 0x00, 0x42},
	{0xB2, 0x00, 0x10},
	{0xB2, 0x00, 0x10},
	{0xB2, 0x00, 0x10},
	[IBRIGHTNESS_465NIT ... IBRIGHTNESS_600NIT] = {0xB2, 0x00, 0x10}
};

/* platform brightness <-> gamma level */
static unsigned int brightness_table[EXTEND_BRIGHTNESS + 1] = {
	[0 ... 1] =		IBRIGHTNESS_002NIT,
	[2 ... 2] =		IBRIGHTNESS_003NIT,
	[3 ... 3] =		IBRIGHTNESS_004NIT,
	[4 ... 4] =		IBRIGHTNESS_005NIT,
	[5 ... 5] =		IBRIGHTNESS_006NIT,
	[6 ... 6] =		IBRIGHTNESS_007NIT,
	[7 ... 7] =		IBRIGHTNESS_008NIT,
	[8 ... 8] =		IBRIGHTNESS_009NIT,
	[9 ... 9] =		IBRIGHTNESS_010NIT,
	[10 ... 10] =		IBRIGHTNESS_011NIT,
	[11 ... 11] =		IBRIGHTNESS_012NIT,
	[12 ... 12] =		IBRIGHTNESS_013NIT,
	[13 ... 13] =		IBRIGHTNESS_014NIT,
	[14 ... 14] =		IBRIGHTNESS_015NIT,
	[15 ... 15] =		IBRIGHTNESS_016NIT,
	[16 ... 16] =		IBRIGHTNESS_017NIT,
	[17 ... 18] =		IBRIGHTNESS_019NIT,
	[19 ... 19] =		IBRIGHTNESS_020NIT,
	[20 ... 20] =		IBRIGHTNESS_021NIT,
	[21 ... 21] =		IBRIGHTNESS_022NIT,
	[22 ... 22] =		IBRIGHTNESS_024NIT,
	[23 ... 23] =		IBRIGHTNESS_025NIT,
	[24 ... 25] =		IBRIGHTNESS_027NIT,
	[26 ... 26] =		IBRIGHTNESS_029NIT,
	[27 ... 27] =		IBRIGHTNESS_030NIT,
	[28 ... 29] =		IBRIGHTNESS_032NIT,
	[30 ... 31] =		IBRIGHTNESS_034NIT,
	[32 ... 33] =		IBRIGHTNESS_037NIT,
	[34 ... 34] =		IBRIGHTNESS_039NIT,
	[35 ... 36] =		IBRIGHTNESS_041NIT,
	[37 ... 38] =		IBRIGHTNESS_044NIT,
	[39 ... 41] =		IBRIGHTNESS_047NIT,
	[42 ... 43] =		IBRIGHTNESS_050NIT,
	[44 ... 45] =		IBRIGHTNESS_053NIT,
	[46 ... 47] =		IBRIGHTNESS_056NIT,
	[48 ... 50] =		IBRIGHTNESS_060NIT,
	[51 ... 53] =		IBRIGHTNESS_064NIT,
	[54 ... 56] =		IBRIGHTNESS_068NIT,
	[57 ... 58] =		IBRIGHTNESS_072NIT,
	[59 ... 62] =		IBRIGHTNESS_077NIT,
	[63 ... 65] =		IBRIGHTNESS_082NIT,
	[66 ... 69] =		IBRIGHTNESS_087NIT,
	[70 ... 73] =		IBRIGHTNESS_093NIT,
	[74 ... 76] =		IBRIGHTNESS_098NIT,
	[77 ... 80] =		IBRIGHTNESS_105NIT,
	[81 ... 84] =		IBRIGHTNESS_111NIT,
	[85 ... 89] =		IBRIGHTNESS_119NIT,
	[90 ... 94] =		IBRIGHTNESS_126NIT,
	[95 ... 99] =		IBRIGHTNESS_134NIT,
	[100 ... 104] =		IBRIGHTNESS_143NIT,
	[105 ... 110] =		IBRIGHTNESS_152NIT,
	[111 ... 116] =		IBRIGHTNESS_162NIT,
	[117 ... 121] =		IBRIGHTNESS_172NIT,
	[122 ... 128] =		IBRIGHTNESS_183NIT,
	[129 ... 135] =		IBRIGHTNESS_195NIT,
	[136 ... 142] =		IBRIGHTNESS_207NIT,
	[143 ... 149] =		IBRIGHTNESS_220NIT,
	[150 ... 157] =		IBRIGHTNESS_234NIT,
	[158 ... 165] =		IBRIGHTNESS_249NIT,
	[166 ... 174] =		IBRIGHTNESS_265NIT,
	[175 ... 183] =		IBRIGHTNESS_282NIT,
	[184 ... 193] =		IBRIGHTNESS_300NIT,
	[194 ... 201] =		IBRIGHTNESS_316NIT,
	[202 ... 210] =		IBRIGHTNESS_333NIT,
	[211 ... 219] =		IBRIGHTNESS_350NIT,
	[220 ... 223] =		IBRIGHTNESS_357NIT,
	[224 ... 227] =		IBRIGHTNESS_365NIT,
	[228 ... 230] =		IBRIGHTNESS_372NIT,
	[231 ... 234] =		IBRIGHTNESS_380NIT,
	[235 ... 238] =		IBRIGHTNESS_387NIT,
	[239 ... 242] =		IBRIGHTNESS_395NIT,
	[243 ... 246] =		IBRIGHTNESS_403NIT,
	[247 ... 250] =		IBRIGHTNESS_412NIT,
	[251 ... 281] =		IBRIGHTNESS_420NIT,
	[282 ... 295] =		IBRIGHTNESS_465NIT,
	[296 ... 309] =		IBRIGHTNESS_488NIT,
	[310 ... 323] =		IBRIGHTNESS_510NIT,
	[324 ... 336] =		IBRIGHTNESS_533NIT,
	[337 ... 350] =		IBRIGHTNESS_555NIT,
	[351 ... 364] =		IBRIGHTNESS_578NIT,
	[EXTEND_BRIGHTNESS ... EXTEND_BRIGHTNESS] =		IBRIGHTNESS_600NIT
};

#endif /* __S6E3FA3_A7MAX_PARAM_H__ */
