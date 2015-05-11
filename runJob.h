#ifndef RUNJOB_H
#define RUNJOB_H
#include <stdio.h>
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include <mpi.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
#define MAX_Q_V 10
#define MAX_Q_E 10
#define FIN -10
#define WenHao 0
#define NoL -3
#define NotFinished -5
#define PATTAG 2
#define MAPTAG 1
#define DATATAG 3
#define OUTPUTPATH "../out/ans"

struct Node{
    Node * next;
    int EID;
    int VID;
    Node(){
        next = NULL;
        EID = -1;
        VID = -1;
    }
};

struct List{
    Node * first;
    List * next;
    int Num_Child;
    int VID;
    List(){
        first = NULL;
        next = NULL;
        VID = -1;
        Num_Child = 0;
    }
};

struct Node_P{
    Node_P * next;
    int EID;
    int VID;
    int EPOS;
    int type;
    Node_P(){
        next = NULL;
        EID = -1;
        VID = -1;
        type = -1;
        EPOS = -1;
    }
};

struct List_P{
    Node_P * first;
    List_P * next;
    int Num_Child;
    int VID;
    int type;
    int VPOS;
    List_P(){
        type = -1;
        first = NULL;
        next = NULL;
        VID = -1;
        VPOS = -1;
        Num_Child = 0;
    }
};
    

class runJob
{
    public:

        vector<List *>Index;
        vector<List_P *>Index_P;
        map<int,int> VID_VPOS;
        
        List *Map = NULL;
        int Id_Pat[MAX_Q_V][MAX_Q_V];
        
        int Num_p;
        int Num_v;
        int Num_e;
        int myid;

        runJob();
        bool InsertList(int VID);
        bool InsertNode(int FVID,int EID,int TVID,bool Data);
        bool InsertList_P(int VID, int type);
        bool LoadFile();
        bool LoadPattern();
        void GetIdPat();
        void OutPut(int myid);
        void OutPattern(int myid);
        void Run();
        int GetEdge(int from, int to);
        void GetAnswer(int VID,int vpos,vector<int> vertex,vector<int> edge);
        int GetEPOS(int from,int to);
        void GiveOthers(vector<int> vertex, vector<int> edge);
        void OutPutAns(vector<int> vertex, vector<int> edge);
        List_P * GetList(int VID);

        virtual ~runJob();
    protected:
    private:
        List_P *Map_P = NULL;//The head of the pattern map
};

#endif // RUNJOB_H
