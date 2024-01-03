//
// Created by Rick Lattin on 3/5/21.
//

#ifndef INC_21S_PA02_LATTIRIC_ANALYZETEXT_H
#define INC_21S_PA02_LATTIRIC_ANALYZETEXT_H

#include "Page.h"
#include "DSVector.h"
#include "DSString.h"

class AnalyzeText {
    private:
        DSVector<Page> allPages;                        //each page
        DSVector<DSString> keywords;                    //each keyword
        DSVector<DSString> keywordsOrdered;             //each keyword in alphabetical order
        DSVector<DSVector<DSString>> keyLocations;      //the page numbers where each keyword occurs

        char* file1;                                    //input/output files
        char* file2;
        char* file3;

    public:
        AnalyzeText();                      //constructors
        AnalyzeText(char*, char*, char*);
        void fillKeywords();                //fills keywords vector with DSStrings for the words
        void sortKeywords();                //sorts the keywords vector into the keywordsOrdered vector in alphabetical order
        void fillAllPages();                //reads all text from pages into Page objects and into the allPages vector
        void fillKeyLocations();            //fills keyLocations vector with vectors of ints for page numbers that the keywords appear on
        void orderOut();                    //Outputs the keywords and their page numbers in the correct format
};

#endif //INC_21S_PA02_LATTIRIC_ANALYZETEXT_H
