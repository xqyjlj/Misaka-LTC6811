/**
 * @file ltc6811.h
 * @brief
 * @author xqyjlj (xqyjlj@126.com)
 * @version 0.0
 * @date 2021-07-22
 * @copyright Copyright © 2020-2021 xqyjlj<xqyjlj@126.com>
 *
 * *********************************************************************************
 * @par ChangeLog:
 * <table>
 * <tr><th>Date       <th>Version <th>Author  <th>Description
 * <tr><td>2021-07-22 <td>0.0     <td>xqyjlj  <td>内容
 * </table>
 * *********************************************************************************
 */
#ifndef __MISAKA_LTC6811_H__
#define __MISAKA_LTC6811_H__

#include "ltc6811_base.h"

typedef struct
{
    uint8_t     gpiox;
    uint8_t     refon;
    uint8_t     dten;       //只读位
    uint8_t     adcopt;
    uint16_t    vuv;
    uint16_t    vov;
    uint8_t     dcto;
} misaka_ltc6811_cfgr_struct;

#define misaka_ltc6811_delay_unit 3

uint8_t misaka_ltc6811_wakeidle(void);
uint8_t misaka_ltc6811_wrcfga(misaka_ltc6811_cfgr_struct* cfgr);
uint8_t misaka_ltc6811_rdcfga(void);
uint8_t misaka_ltc6811_rdcva(void);
uint8_t misaka_ltc6811_rdcvb(void);
uint8_t misaka_ltc6811_rdcvc(void);
uint8_t misaka_ltc6811_rdcvd(void);
uint8_t misaka_ltc6811_rdauxa(void);
uint8_t misaka_ltc6811_rdauxb(void);
uint8_t misaka_ltc6811_rdstata(void);
uint8_t misaka_ltc6811_rdstatb(void);
uint8_t misaka_ltc6811_wrsctrl(void);
uint8_t misaka_ltc6811_wrpwm(void);
uint8_t misaka_ltc6811_rdsctrl(void);
uint8_t misaka_ltc6811_rdpwm(void);
uint8_t misaka_ltc6811_stsctrl(void);
uint8_t misaka_ltc6811_clrsctrl(void);
uint8_t misaka_ltc6811_adcv(uint16_t md, uint8_t dcp, uint8_t ch);
uint8_t misaka_ltc6811_adow(uint16_t md, uint8_t pup, uint8_t dcp, uint8_t ch);
uint8_t misaka_ltc6811_cvst(uint16_t md, uint8_t st);
uint8_t misaka_ltc6811_adol(uint16_t md, uint8_t dcp);
uint8_t misaka_ltc6811_adax(uint16_t md, uint8_t chg);
uint8_t misaka_ltc6811_adaxd(uint16_t md, uint8_t chg);
uint8_t misaka_ltc6811_axst(uint16_t md, uint8_t st);
uint8_t misaka_ltc6811_adstat(uint16_t md, uint8_t chst);
uint8_t misaka_ltc6811_adstatd(uint16_t md, uint8_t chst);
uint8_t misaka_ltc6811_statst(uint16_t md, uint8_t st);
uint8_t misaka_ltc6811_adcvax(uint16_t md, uint8_t dcp);
uint8_t misaka_ltc6811_adcvsc(uint16_t md, uint8_t dcp);
uint8_t misaka_ltc6811_clrcell(void);
uint8_t misaka_ltc6811_clraux(void);
uint8_t misaka_ltc6811_clrstat(void);
uint8_t misaka_ltc6811_pladc(void);
uint8_t misaka_ltc6811_diagn(void);
uint8_t misaka_ltc6811_wrcomm(void);
uint8_t misaka_ltc6811_rdcomm(void);
uint8_t misaka_ltc6811_stcomm(void);
uint8_t misaka_ltc6811_calculate_cell_voltage(void);
uint8_t misaka_ltc6811_read_all_cell_voltage(uint16_t md, uint8_t dcp, uint8_t ch);
uint8_t misaka_ltc6811_calculate_auxiliary_voltage(void);
uint8_t misaka_ltc6811_read_all_auxiliary_voltage(uint16_t md, uint8_t chg);
uint8_t misaka_ltc6811_calculate_status(void);
uint8_t misaka_ltc6811_read_all_status(uint16_t md, uint8_t chst);
uint8_t misaka_ltc6811_cell_voltage_self_test(uint16_t md, uint8_t st, uint16_t stc);
uint8_t misaka_ltc6811_auxiliary_voltage_self_test(uint16_t md, uint8_t st, uint16_t stc);
uint8_t misaka_ltc6811_status_voltage_self_test(uint16_t md, uint8_t st, uint16_t stc);
uint8_t misaka_ltc6811_status_self_test(uint16_t md, uint8_t st, uint16_t stc);
uint8_t misaka_ltc6811_open_wire_check(uint16_t md, uint8_t dcp, uint8_t ch);
uint8_t misaka_ltc6811_balance_group(uint8_t group);
void misaka_ltc6811_dcc_flag(uint8_t balance_threshold);
void misaka_ltc6811_max_cell_voltage();
void misaka_ltc6811_min_cell_voltage();
uint8_t misaka_ltc6811_self_test(uint16_t md, uint8_t st, uint16_t stc);

#endif
