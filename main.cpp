#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <fstream>
#include "DSVector.h"

#include "catch.hpp"
#include "AnalyzeText.h"

int main(int argc, char** argv) {

    int result = 0;
    if(argc > 1){
        AnalyzeText book(argv[1], argv[2], argv[3]);
        book.fillKeywords();
        book.fillAllPages();
        book.sortKeywords();
        book.fillKeyLocations();
        book.orderOut();



    }
    else{                             //run test
        result = Catch::Session().run(argc, argv);
    }
    return result;
}
