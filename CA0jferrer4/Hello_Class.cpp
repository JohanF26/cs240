#include <iostream>
#include <stdlib.h>
#include "Hello_Class.h"

Hello_Class::Hello_Class(int i) {
	if (i == 0) {
    	output_string = "Hello C++ Data Structures, from Johan!";
	} else {
    	output_string = "Hello Data Structures!";
	}
}
void Hello_Class::print_hello() {
	cout << output_string << endl;
};
