#ifndef STATUS_H
#define STATUS_H

extern void status_cracked(int ans, char *word);
extern void status_no_cracked();
extern void status_time(double (*show_time)(), clock_t duration, long long wn);

#endif
