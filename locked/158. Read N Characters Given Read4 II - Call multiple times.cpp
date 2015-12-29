The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function may be called multiple times.

// Forward declaration of the read4 API.
int read4(char *buf);
 
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    queue<char> tank;
    int read(char *buf, int n) {
        int w = 0, wBuf;
        char *pBuf = buf;
        while (w < n && !tank.empty()) {
            *pBuf = tank.front();
            tank.pop();
            w++;
            pBuf++;
        }
        while (w < n && (wBuf = read4(pBuf)) ) {
            w += wBuf;
            pBuf += wBuf;
        }
        if (w >= n) {
            for (int i = 0; i < w-n; i++) {
                tank.push(pBuf[n-w+i]);
            }
            pBuf[n-w] = '\0';
            w = n;
        }
        buf += w;
        return w;
    }
};