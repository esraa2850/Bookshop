/*
 Boost Software License - Version 1.0 - October 29th, 2024

 Permission is hereby granted, free of charge, to any person or organization
 obtaining a copy of the software and accompanying documentation covered by
 this license (the "Software") to use, reproduce, display, distribute,
 execute, and transmit the Software, and to prepare derivative works of the
 Software, and to permit third-parties to whom the Software is furnished to
 do so, all subject to the following:

 The copyright notices in the Software and this entire statement, including
 the above license grant, this restriction and the following disclaimer,
 must be included in all copies of the Software, in whole or in part, and
 all derivative works of the Software, unless such copies or derivative
 works are solely in the form of machine-executable object code generated by
 a source language processor.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 DEALINGS IN THE SOFTWARE.
 */
#include "Data.h"
#include <fstream>
#include <sstream>

// Pointer functions



// Load data from files to memory
/*void importData() {
    readCSVfile("data_book.csv");
	readCSVfile("admin_book.csv");
	readCSVfile("user_data.csv");
    cout << "\nAll data has been loaded successfully....\n";
}*/

/*void readCSVfile(string filename) {
    std::ifstream inputFile();
    string fileReName = "./data/" + filename;

    // Open file with relative path
    file.open(fileReName, ios::in);
    if (!file.is_open()) {
        file.close();
        return;
    }

    string line, word, heading;
    vector <string> data;

    // Detect which file will be loaded
    if (filename == "data_book.csv") {
        loadData = &loadBooks;
    } else if (filename == "admin_data.csv") {
        loadData = &loadAdmin;
    } else if (filename == "user_data.csv") {
        loadData = &loadusers;
    }
    // Skip heading
    getline(file, heading);

    // Read until end of the file
    while(!file.eof()) {
        // Clear previous data
        data.clear();

        // Read line
        getline(file, line);
        stringstream words(line);

        // Sperete the line to strings by dilimiter
        while(getline(words, word, ',')) {
            data.push_back(word);
        }

        // Skip empty line
        if (data.size() == 0)
            continue;

        loadData(data);
    }

    file.close();
}*/

/*void loadBooks( vector <Book> books){
    // Store Book info
    std::ifstream inputFile("data_book.csv");
    Book info;
    if(inputFile.is_open()){
        string line, word, heading;
        // Skip heading
        //getline("data_book.csv", heading);

    while(inputFile>>info.code>>info.title>>info.type>>info.author>>info.price)
    {
        books.push(info);
    }
    inputFile.close();
    }
    else{
        std::cerr<<"Unable to open file";
    }

}
*/


