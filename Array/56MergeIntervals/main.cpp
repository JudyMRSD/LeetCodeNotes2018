#include <iostream>
#include <vector>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval(): start(0), end(0){}
    Interval(int s, int e): start(s), end(e) {}
};

/**
 * function defined here, outside of a class is static
 * static member functions are not attached to any particular object
 */
bool mySort(Interval a, Interval b) {
    return (a.start < b.start);
}

class Solution {
//sort using ascending order by start value of intervals

public:
    /**
     * cannot use like following here, mySort is a nonstatic member function of class Solution,
     * nonstatic function need to be used as  Solution s = Solution(),  s.mySrot,
     *
     bool mySort(Interval a, Interval b) {
        return (a.start < b.start);
     }


    can use if change it to static, since static member functions are not attached to any particular object

    static bool mySort(Interval a, Interval b) {
        return (a.start < b.start);
    }

    */
    vector<Interval> merge(vector<Interval> &intervals) {
        //resulting merged Intervals
        vector<Interval> res;
        if (intervals.size() == 0) {
            return res;
        }
        vector<int> startV(intervals.size());
        vector<int> endV(intervals.size());
        for (int i = 0; i < intervals.size(); i++) {
            startV[i] = intervals[i].start;
            endV[i] = intervals[i].end;
        }
        //sort using startV values
        //sort is an STL algorithm, is a static function, cannot use non static
        /*
         * When called, a static function isn't bound to an instance of the class.
         * Class instances (objects) are going to be the entities that hold the "non-static" variables.
         * Therefore, from the static function, you won't be able to access them without actually
         * being passed or storing elsewhere a specific instance to operate on.
         *
         * Static member functions are allowed to access only the static data members
         * or other static member functions,
         * they can NOT access the non-static data members or member functions of the class.
         */
        sort(intervals.begin(), intervals.end(), mySort);
        //if endV of the current pair is larger than startV of next pair
        //meaning there is overlap
        //take the larger one of the two endV as the new endV
        Interval tmp = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            //has overlap
            if (tmp.end >= intervals[i].start) {
                //merge
                tmp.end = max(tmp.end, intervals[i].end);
            }//no overlap
            else {
                //store into the result
                res.push_back(tmp);
                //update
                tmp = intervals[i];
            }
        }
        //store the last tmp
        res.push_back(tmp);
        return res;
    }
};

int main() {
    Interval a(1,2);
    Interval b(2,3);
    vector<Interval> intervals;
    intervals.push_back(a);
    intervals.push_back(b);
    Solution s = Solution();
    vector<Interval> res = s.merge(intervals);
    cout<<res.size()<<endl;
}