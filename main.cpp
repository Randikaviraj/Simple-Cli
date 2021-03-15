#include "Controller.h"

int main(){
    Catalog catalog;
    View view(catalog);
    Controller controller(view,catalog);
    controller.start_cli();

    return 0;
}