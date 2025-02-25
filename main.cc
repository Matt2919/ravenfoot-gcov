#include "/public/read.h"
#include <vector>
#include "Vector.h"
#include "VectorGPT.h"
#include "VectorSTD.h"
#include <algorithm>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;

// YOU: Write a function to print values in STL vector here

void printTime(int size, double time)
{
	cout << fixed << setprecision(6) << time << " s [" << size << "]" << endl;
}

int main(int argc, char **argv) {
    const size_t SIZE = 1'000'000; // You will benchmark up to 1'000'000
                                   // Creating a constants about which mode you benchmark
    enum MODE { STL, YOU, GPT };
    int mode = STL;
    if (argc > 2) mode = atoi(argv[1]); //Read mode from command line parameters
                                        //If no command line parameter (a.out 0 or a.out 1) is provided, then read from keyboard
    else mode = read("Choose mode:\n0) STL Vector\n1) Your Vector\n2) GPT Vector\n");
    if (mode < STL or mode > GPT) mode = STL;
    cerr << "Mode == " << mode << endl;

    // if (mode == STL) vector<int> stlVec(SIZE);
    // YOU: Add your vector declaration here
    // YOU: Add GPT vector declaration here

	vector<int> sizeAmount = {10, 100, 1'000, 10'000, 100'000, 250'000, 500'000, 750'000, 1'000'000};

    while (cin) {
        string s;
        cin >> s;
        if (!cin) break;
        if (s == "INSERT") {
            int x = 0;
			int inp;
			int inp2;
            cin >> inp;
			cin>> inp2;
            if (!cin) break;
            // YOU: Implement ".push_back()" or ".insert()" depending on vector choice

			if (mode == STL)
			{
				for (int i = 0; i < sizeAmount.size(); i++)
				{
					if (inp==1){
					if (i==1) break;
					}
					VectorSTD stdVec;
					double startTime = clock();
					x=0;
					for (int j = 0; j < sizeAmount.at(i); j++)
					{x++;
						stdVec.push_back(x);
						stdVec.insert(inp2, x);
	
					}
					if ((inp==1)||(inp==2)){
					for (int j = 0; j <stdVec.get_size(); j++) {
						cout << stdVec.at(j) << " ";
					}}

					double endTime = clock();
					double totalTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
					printTime(sizeAmount.at(i), totalTime);
				}
			}
			else if (mode == YOU)
			{
			
				for (int i = 0; i < sizeAmount.size(); i++)
                {
				if(inp==1){	if (i==1)break;}

                    Vector youVec;


					double startTime = clock();
					x=0;
					for (int j = 0; j < sizeAmount.at(i); j++)
					{x++;
                    	youVec.push_back(x);
                    	youVec.insert(inp2, x);
					}
					if ((inp==1)||(inp==2)){
					for (int j = 0; j <youVec.get_size(); j++) {
						cout << youVec.at(j) << " ";
					}
					cout << endl<<"print start" << endl;
					youVec.print_vec();
					cout << "print done" <<endl;
					}

                    double endTime = clock();
                    double totalTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
                    printTime(sizeAmount.at(i), totalTime);
                  }
			}
			else if (mode == GPT)
			{
				for (int i = 0; i < sizeAmount.size(); i++)
				{
				if(inp==1){	if (i==1) break;}
					VectorGPT gptVec;
					gptVec.resize(sizeAmount.at(sizeAmount.size() - 1));

					double startTime = clock();
					x=0;
					for (int j = 0; j < sizeAmount.at(i); j++)
					{
						gptVec.push_back(x);
						gptVec.insert(inp2, x);
					}
					if ((inp==1)||(inp==2)){
						for (int j = 0; j <sizeAmount.at(i); j++) {
						cout << gptVec.at(j) << " ";
					}
					}
				
					double endTime = clock();
					double totalTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
					printTime(sizeAmount.at(i), totalTime);
				}
			}
			
        }
        else if (s == "SEARCH") {
            int x=0;
            cin >> x;
            if (!cin) break;
            // YOU: Implement ".find()" depending on vector choice

			if (mode == STL)
              {
                  for (int i = 0; i < sizeAmount.size(); i++)
                  {
					  VectorSTD stdVec;
						double startTime = clock();

                      for (int j = 0; j < sizeAmount.at(i); j++)
					{
                      stdVec.push_back(x);
                      stdVec.insert(0, x);
					  stdVec.contains(x);
					}

                      double endTime = clock();
                      double totalTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
                      printTime(sizeAmount.at(i), totalTime);
                  }
              }
			else if (mode == YOU)
              {
                  for (int i = 0; i < sizeAmount.size(); i++)
                  {
                      double startTime = clock();

                      Vector youVec;
                      youVec.resize(sizeAmount.at(sizeAmount.size() - 1));

					for (int j = 0; j < sizeAmount.at(i); j++)
					{
                      youVec.push_back(x);
                      youVec.insert(0, x);
					  youVec.contains(x);
					}

                      double endTime = clock();
                      double totalTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
                      printTime(sizeAmount.at(i), totalTime);
                    }
              }
			else if (mode == GPT)
              {
                  for (int i = 0; i < sizeAmount.size(); i++)
                  {
                      double startTime = clock();

                      VectorGPT gptVec;
                      gptVec.resize(sizeAmount.at(sizeAmount.size() - 1));

					for (int j = 0; j < sizeAmount.at(i); j++)
					{
                      gptVec.push_back(x);
                      gptVec.insert(0, x);
					  gptVec.contains(x);
					}

                      double endTime = clock();
                      double totalTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
                      printTime(sizeAmount.at(i), totalTime);
                  }
              }
        }
        else if (s == "REMOVE") {
            int x = 0;
			cin >> x;
			if (!cin) break;
			// YOU: Implement ".pop_back()" or ".erase()" depending on vector choice

			if (mode == STL)
              {
                  for (int i = 0; i < sizeAmount.size(); i++)
                  {
                      double startTime = clock();

                      VectorSTD stdVec;

						for (int j = 0; j < sizeAmount.at(i); j++)
					{
                      stdVec.push_back(x);
                      stdVec.insert(0, x);
					  stdVec.contains(x);
					  stdVec.pop_back();
					}

                      double endTime = clock();
                      double totalTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
                      printTime(sizeAmount.at(i), totalTime);
                  }
              }
			else if (mode == YOU)
              {
                  for (int i = 0; i < sizeAmount.size(); i++)
                  {
                      double startTime = clock();

                      Vector youVec;
 
					for (int j = 0; j < sizeAmount.at(i); j++)
					{
                      youVec.push_back(x);
                      youVec.insert(0, x);
					  youVec.contains(x);
					  youVec.pop_back();
					}

                      double endTime = clock();
                      double totalTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
                      printTime(sizeAmount.at(i), totalTime);
                    }
              }
			else if (mode == GPT)
              {
                  for (int i = 0; i < sizeAmount.size(); i++)
                  {
                      double startTime = clock();

                      VectorGPT gptVec;
                      gptVec.resize(sizeAmount.at(sizeAmount.size() - 1));

					for (int j = 0; j < sizeAmount.at(i); j++)
					{
                      gptVec.push_back(x);
                      gptVec.insert(0, x);
					  gptVec.contains(x);
					  gptVec.pop_back();
					}

                      double endTime = clock();
                      double totalTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
                      printTime(sizeAmount.at(i), totalTime);
                  }
              }
        }
        else break;
    }


}
