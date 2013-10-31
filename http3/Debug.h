#ifndef DEBUG_H
#define	DEBUG_H

class Debug {
public:
    Debug();
    Debug(const Debug& orig);
    static void thread_sleep(double secs);
    virtual ~Debug();
private:

};

#endif	/* DEBUG_H */

