#include <iostream>
#include <sstream>

#include "common.hpp"

#ifndef TESTCASE_HPP
#define TESTCASE_HPP

size_t load_testcases(string filename, 
        size_t n_queries, 
        vector<vid_type> &testcases,
        string mode = "single_q"){
    if (mode != "single_q" && mode != "multi_q") {
        cerr << "Not supported query type!" << endl;
        return -1;
    }
    set<vid_type> visited_vertices;
    ifstream in(filename.c_str());
    while(testcases.size() < n_queries) {
        string test_line;
        if(in.eof()) {
            cout << "Not enough test cases, reach end of testcase file"<< endl;
            break;
        }
        getline(in, test_line);
        if (test_line.empty())
            continue;
        stringstream ss(test_line);
        if (mode == "single_q") {
            int test = -1;
            ss >> test;
            // cout << "Read test query vertex " << test 
                // << " from " << test_line;
            if (visited_vertices.find(test) == visited_vertices.end()) {
                testcases.push_back(test);
                visited_vertices.insert(test);
                // cout << " saved!" << endl;
            }
            // cout << " not saved!" << endl;
        }
        else {
            // TODO: implement multi q
            cerr << "Not implemented yet" << endl;
            return -1;
        }
    }
    in.close();

    return testcases.size();
}

#endif
