#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <fstream>
#include <list>

using namespace std;
    ifstream ifs;
    ofstream ofs;
    
void storeInfoVectorAndSortInfoMap(string fileToRead) {
    
    string out_fileName(fileToRead + string("_vector") + ".txt");
    string mapFileName(fileToRead + string("_1_1.txt"));
    string next_line;
    vector <string> wordVector;
    ifs.open(fileToRead.c_str());
    ofs.open(out_fileName.c_str());
    while(getline(ifs, next_line)) {
        istringstream iss(next_line);
        string temp;
        while(iss >> temp) {
            string nopunct = "";
            for(auto const &c : temp) {
                if (isalpha(c)) {
                    nopunct += c;
                }
            }
            wordVector.push_back(nopunct);
        }
    }
    
    for(int i = 0; i < wordVector.size(); i++) {
        ofs << wordVector.at(i) << endl;
    }
    ifs.close();
    ofs.close();
    
    ofs.open(mapFileName);
    
    map <string, string> wordMap;
    string last = "";
    for(vector <string>::iterator it = wordVector.begin(); it != wordVector.end(); it++) {
        wordMap[last] = *it;
        last = *it;
    }
    
    for(map <string, string>::iterator it = wordMap.begin(); it != wordMap.end(); it++) {
        ofs << it->first << ", " << it->second << endl;
    }
    ofs << endl;
    
    ofs.close();
    cout << "Infinite Loop Map" << endl;
    string state = "";
    for(int i = 0; i < 100; i++){
        cout << wordMap[state] << " ";
        state = wordMap[state];
    }
    cout << endl << endl;
    
    cout << "Organized Sermon/Poem/etc." << endl;
    map<string, vector<string>> organizeWordMap;
    string organizeState = "";
    for(vector<string>::iterator it=wordVector.begin(); it !=wordVector.end(); it++) {
        organizeWordMap[state].push_back(*it);
        organizeState = *it;
    }
    
    srand(time(NULL));
    
    organizeState = "";
    
    for(int i = 0; i < 100; i++) {
        int ind = rand() % organizeWordMap[state].size();
        cout << organizeWordMap[state][ind] << " ";
        organizeState = organizeWordMap[state][ind];
    }
    cout << endl << endl;
    
    
    
    cout << "Organize by using List" << endl;
    int M = 2;
    list <string> listState;
    map <list<string>, vector<string>> listWordMap;
    
    
    for(int i = 0; i < M; i++) {
        listState.push_back("");
    }
    
    for(vector <string>::iterator it = wordVector.begin(); it != wordVector.end(); it++) {
        listWordMap[listState].push_back(*it);
        listState.push_back(*it);
        listState.pop_front();
    }
    
    listState.clear();
    
    for(int i = 0; i < M; i++) {
        listState.push_back("");
    }
    
    for(int i = 0; i < 100; i++) {
        int ind = rand() % listWordMap[listState].size();
        cout << listWordMap[listState][ind] << " ";
        listState.push_back(listWordMap[listState][ind]);
        listState.pop_front();
    }
    cout << endl;
    
    return;
}

void storeInfoSet(string fileToRead) {
    
    string out_fileName(fileToRead + string("_set") +".txt");
    ifs.open(fileToRead.c_str());
    ofs.open(out_fileName.c_str());
    string next_line;
    set <string> wordSet;
    while(getline(ifs, next_line)) {
        istringstream iss(next_line);
        string temp;
        while(iss >> temp) {
            string nopunct = "";
            for(auto const &c : temp) {
                if (isalpha(c)) {
                    nopunct += c;
                }
            }
            wordSet.insert(nopunct);
        }
    }
    for(set <string>::iterator it = wordSet.begin(); it != wordSet.end(); ++it) {
        ofs << *it << endl;
    }
    
    ifs.close();
    ofs.close();
    
    return;
}

void sortInfoUniquely(string fileToRead) {
    
}

int main(int argc, char* argv[]) {
    

    
    string fileName(argv[1] + string(".txt"));
    
    storeInfoSet(fileName); //reads words into file with a set.
    
    storeInfoVectorAndSortInfoMap(fileName); 
    //reads file into vector and organizes sermons in maps showing the difference between using vectors and lists to make a more organized sermon.
    
    sortInfoUniquely(fileName);
    return 0;
}