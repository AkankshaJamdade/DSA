class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        
        // Convert MM-DD into number of days from the beginning of the year
        int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto convert = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            int total = day;

            for (int i = 1; i < month; i++) {
                total += days[i];
            }

            return total;
        };

        int aStart = convert(arriveAlice);
        int aEnd = convert(leaveAlice);

        int bStart = convert(arriveBob);
        int bEnd = convert(leaveBob);

        // Find overlapping range
        int start = max(aStart, bStart);
        int end = min(aEnd, bEnd);

        // No overlap
        if (start > end)
            return 0;

        // +1 because both start and end days are included
        return end - start + 1;
    }
};