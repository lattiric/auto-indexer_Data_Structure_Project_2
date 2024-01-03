//
// Created by Rick Lattin on 3/4/21.
//

#ifndef INC_21S_PA02_LATTIRIC_PAGE_H
#define INC_21S_PA02_LATTIRIC_PAGE_H

#include <map>
#include "DSVector.h"
#include "DSString.h"

class Page{
    private:
        DSVector<DSString> pageWords;       //all text on a page on multiple lines
        DSString pageNum;                   //page number as a DSString

    public:
        Page();             //constructor

        DSVector<DSString>& getPageWords();        //set/get functions
        DSString getPageNum();
        void setPageNum(DSString);
};

#endif //INC_21S_PA02_LATTIRIC_PAGE_H
