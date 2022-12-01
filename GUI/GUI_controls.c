#include "GUI_constants.h"



void controll_home_page(int *key)
{
    short local_address = HOME_PAGE_ADDRESS;
    switch (*key)
    {
    case 1:
        set_text_home_address(PAGE_1_ADDRESS);
        MODE = MODE_PAGE_1_DATATABLE_VIEW;
        break;
    case 2:
        set_text_home_address(PAGE_2_ADDRESS);
        MODE = MODE_PAGE_2_OPTIONS_EDIT;
        break;
    case 3:
        set_text_home_address(PAGE_3_ADDRESS);
        MODE = MODE_PAGE_3_GREENHOUSE_VIEW;
        break;

    default:
        MODE = MODE_HOME_PAGE_MENU_VIEW;
        break;
    }
}

void controll_page_1_table(int *key)
{
    if (*key == 10 || *key == 12)
    {
        set_text_home_address(HOME_PAGE_ADDRESS);
        MODE = MODE_HOME_PAGE_MENU_VIEW;
    }
}
void controll_page_2_view(int *key)
{
    switch (*key)
    {
    case 1:
        MODE = MODE_TEMP_LOW_EDIT;
        break;
    case 2:
        MODE = MODE_TEMP_HIGH_EDIT;
        break;
    case 3:
        MODE = MODE_DATE_EDIT;
        break;
    case 4:
        MODE = MODE_CLOCK_EDIT;
        break;
    case 10:
        set_text_home_address(HOME_PAGE_ADDRESS);
        MODE = MODE_HOME_PAGE_MENU_VIEW;

    default:
        break;
    }
}
void controll_page_3_view(int *key)
{
    switch (*key)
    {
    case 1:
        reset_alram_temp_sensor();
        break;
    case 2:
        set_text_home_address(PAGE_2_ADDRESS);
        MODE = MODE_PAGE_2_OPTIONS_VIEW;
        break;

    default:
        break;
    }
}

void edit_temprature()
{
    // the positision of data on the diplay
    int col_position = 0;

    if (MODE == MODE_TEMP_HIGH_EDIT)
        col_position = 14;
    else if (MODE == MODE_TEMP_LOW_EDIT)
        col_position = 6;
    else
        return;

    // if limit is set: edit the upper limit
    // else: edit the lower limit.

    // set a cursor on the digit to edit
    set_curser_pointer(PAGE_2_ADDRESS, col_position, 2);

    // to store the final value
    short new_temp = 0;

    // reading from keypad, the least significant digit
    int key = button_released();

    if (key == HOME_BUTTON)
        go_home();
    if (key == RETURN_BUTTON)
        return;

    new_temp += key;

    // print on display the new value instead of the old one.
    set_address_pointer(PAGE_2_ADDRESS, col_position, 2);
    print_char(new_temp % 10 + '0');

    // then move cursor to more significant digit
    set_curser_pointer(PAGE_2_ADDRESS, col_position - 1, 2);

    // reading from keypad, the most significant digit
    key = button_released();

    if (key == HOME_BUTTON)
        go_home();
    if (key == RETURN_BUTTON)
        return;

    new_temp += key * 10;

    set_address_pointer(PAGE_2_ADDRESS, col_position - 1, 2);
    print_char(new_temp / 10 + '0');
}

void edit_date()
{
    if (MODE != MODE_DATE_EDIT)
        return;
    int key = 0;
    char date[8] = "00/00/00";

    for (char i = 0; i < 8; i++)
    {
        if (i == 2 || i == 5) // jumb over "/"
            continue;

        set_curser_pointer(PAGE_2_ADDRESS, i, 4);
        key = button_released();

        if (key == HOME_BUTTON)
            go_home();
        if (key == RETURN_BUTTON)
            return;

        set_address_pointer(PAGE_2_ADDRESS, i, 4);
        date[i] = key + '0';
        print_char(key + '0');
    }
}

void edit_clock()
{
    if (MODE != MODE_CLOCK_EDIT)
        return;
    int key = 0;
    char time[8] = "00:00:00";

    for (char i = 0; i < 8; i++)
    {
        if (i == 2 || i == 5) // jumb over ":"
            continue;

        set_curser_pointer(PAGE_2_ADDRESS, i+8, 4);
        key = button_released();

        if (key == HOME_BUTTON)
            go_home();
        if (key == RETURN_BUTTON)
            return;

        set_address_pointer(PAGE_2_ADDRESS, i+8, 4);
        time[i] = key + '0';
        print_char(key + '0');
    }
}
void go_home()
{
    set_text_home_address(HOME_PAGE_ADDRESS);
    MODE = MODE_HOME_PAGE_MENU_VIEW;
}
