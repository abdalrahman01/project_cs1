#include "../lcd_commands.h"
#include "../commands_data_lcd.h"
#include "../keypad.h"
#include "GUI_constants.h"


void daley(int);
void set_address_pointer(unsigned short address, char col, char row)
{
    // address: choose which diplay to use (HOME_PAGE_ADDRESS, PAGE_1_ADDRESS, etc ...)

    // if (col, row) is outside the col.
    if (col > 30 || col < 0 || row < 0 || row > 16)
        return;

    address += (row * 30) + col;

    run_command_op2(SET_ADDRESS_POINTER, address & 0xff, (address & 0xff00) >> 8);
}
void set_curser_pointer(unsigned short address, char col, char row)
{
    // address: choose which diplay to use (HOME_PAGE_ADDRESS, PAGE_1_ADDRESS, etc ...)

    // if (col, row) is outside the col.
    if (col > 30 || col < 0 || row < 0 || row > 16)
        return;

    address += (row * 30) + col;

    run_command_op2(SET_CURSER_POINTER, address & 0xff, (address & 0xff00) >> 8);
}
void set_text_hGUIome_address(unsigned short address)
{
    // address: choose which diplay to use (HOME_PAGE_ADDRESS, PAGE_1_ADDRESS, etc ...)

    run_command_op2(SET_TEXT_HOME_ADDRESS, address & 0xff, (address & 0xff00) >> 8);
    delay(100); // wait 100ms
}

extern char MODE = 0;


void key_listner(int *key)
{
    if (*key == 0)
        return;
    switch (MODE)
    {
    case MODE_HOME_PAGE_MENU_VIEW:
        set_text_home_address(HOME_PAGE_ADDRESS);
        break;
    case MODE_PAGE_1_DATATABLE_VIEW:
        set_text_home_address(PAGE_1_ADDRESS);
        break;
    case MODE_PAGE_2_OPTIONS_VIEW:
        set_text_home_address(PAGE_2_ADDRESS);
        break;
    case MODE_PAGE_3_GREENHOUSE_VIEW:
        set_text_home_address(PAGE_3_ADDRESS);
        break;
    case MODE_TEMP_HIGH_EDIT:
        set_text_home_address(PAGE_2_ADDRESS);
        edit_temprature();
    case MODE_TEMP_LOW_EDIT:
        set_text_home_address(PAGE_2_ADDRESS);
        edit_temprature();
        break;
    case MODE_DATE_EDIT:
        set_text_home_address(PAGE_2_ADDRESS);
        edit_date();
    case MODE_CLOCK_EDIT:
        set_text_home_address(PAGE_2_ADDRESS);
        edit_clock();
        break;

    default:
        break;
    }
}
