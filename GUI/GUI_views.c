#include "GUI_constants.h"
#include "GUI.h"
#include "../lcd_commands.h"



void home_view(){
    char local_address = HOME_PAGE_ADDRESS;

    set_address_pointer(local_address, 13, 0);
    print_word("HELLO" ,5); 

    set_address_pointer(local_address, 13, 0);
    


}

// void page1_view(){
    
// }
// void page1_view(){

// }
// void page1_view(){

// }