//
// Created by Rick Lattin on 2/4/21.
//

#ifndef INC_21S_PA01_DSSTRING_H
#define INC_21S_PA01_DSSTRING_H

#include<iostream>
#include<cstring>

#include<functional>

class DSString {
    private:
        char* data;

        //str_ln(char* );

    public:
        DSString();
        DSString(const char*);         //copy constructors
        DSString(const DSString&);
        ~DSString();                        //destructors

        DSString& operator= (const char*);          //DSString operators
        DSString& operator= (const DSString&);
        DSString operator+ (const DSString&);
        bool operator== (const char*);
        bool operator== (const DSString&);
        bool operator!= (const char*);
        bool operator!= (const DSString&);
        bool operator> (const DSString&) const;
        bool operator< (const DSString&) const;
        char& operator[] (const int);

        int getLength() const;
//        int is_alpha(const DSString);

        DSString substring(int start, int numChars);
        DSString trimExtra();
        DSString trimBasic();
        DSString makeLower();
        DSString makeUpper();

        char* c_str() const;

        friend std::ostream& operator<< (std::ostream&, const DSString&); //cout function

};

namespace std {
    template <> struct hash<DSString> {
        //referenced from https://gist.github.com/codebrainz/8ece2a9015a3ed0d260f
        std::size_t operator()(DSString const& arg) const noexcept {
            size_t h = 5381;
            int c;
            char* ptr = arg.c_str();
            while((c = *ptr++))
                h = ((h << 5) + h) + c;
            return h;
        }
    };
}

#endif //INC_21S_PA01_DSSTRING_H
