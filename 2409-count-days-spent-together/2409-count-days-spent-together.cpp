class Solution {
public:
    int to_day(string& s)
    {
        int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

        int month=int(s[0]-'0')*10+(s[1]-'0');
        int days=int(s[3]-'0')*10 +(s[4]-'0');
        int total_days=days;
        for(int i=1 ; i< month ; i++)
        {
            total_days+=day[i];
        }
        return total_days;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arrive_alice=to_day(arriveAlice);
        int leave_alice=to_day(leaveAlice);
        int arrive_bob=to_day(arriveBob);
        int leave_bob=to_day(leaveBob);

        int start=max(arrive_alice, arrive_bob);
        int end=min(leave_alice, leave_bob);
        if(end>=start)
        {
            return end-start +1;
        }
        return 0;
        
        
    }
};