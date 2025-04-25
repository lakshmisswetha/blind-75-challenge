/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        vector<int> starts, ends;
        for (const auto& interval : intervals) {
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int rooms = 0, end_ptr = 0;

        for (int i = 0; i < starts.size(); ++i) {
            if (starts[i] < ends[end_ptr]) {               
                rooms++;
            } else {                
                end_ptr++;
            }
        }

        return rooms;
    }
};

