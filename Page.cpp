//
// Created by Rick Lattin on 3/4/21.
//
#include "DSString.h"
#include <map>
#include "Page.h"

Page::Page(){
    pageNum = "0";
}

DSVector<DSString>& Page::getPageWords() {
    return pageWords;
}

DSString Page::getPageNum() {
    return pageNum;
}


void Page::setPageNum(DSString str) {
    pageNum = str;
}


