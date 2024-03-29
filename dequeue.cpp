#include <array>;

template <typename T>
class dequeue {
    public:

        dequeue(T arr[], int size) {
            buffer_size = std::max(size, arr.size());
            buffer = new T[buffer_size];
            for(int i = 0; i < arr.size(); i++) {
                buffer[i] = arr[i];
            }
            strt_indx = 0;
            end_indx = arr.size() % buffer_size;
        }

        int length() {
            return end_indx - strt_indx;
        }

        bool push(T val) {
            // We have to check if our start and end indices are colliding into each other. 
            if((end_indx - strt_indx) == buffer_size) {
                resize(buffer_size * 2);
            }
            buffer[end_indx % buffer_size] = val;
            end_indx++;
            return true;
        }

        bool push_back(T val) {
            if((end_indx - strt_indx) == buffer_size) {
                resize(buffer_size * 2);
            }
            strt_indx--;
            buffer[strt_indx % buffer_size] = val;
            return true;
        }

        T pop() {
            if(is_empty()) {
                return NULL;
            } else { 
                end_indx--;
                return buffer[end_indx % buffer_size];
            }
        }

        T pop_back() {
            if(is_empty()) {
                return NULL;
            } else {
                strt_indx++;
                return buffer[(strt_indx - 1) % buffer_size];
            }
        }

        T peek() {
            return buffer[(end_indx - 1) % buffer_size];
        }

        T peek_back() {
            return buffer[strt_indx % buffer_size];
        }

        bool is_empty() {
            return (strt_indx == end_indx);
        }

        bool resize(int new_size) {
            if(new_size == length()){
                return true;
            } elif(new_size > length()) {
                new_buffer = T[new_size];
                for(int i = 0; i < length(); i++){
                    new_buffer[i] = buffer[(strt_indx + i) % buffer_size];
                }
                end_indx = length();
                strt_indx = 0;
                buffer_size = new_size;
                buffer = new_buffer;
                return true;
            } elif(new_size < length()){
                if(new_size > end_indx){
                    // We can simply cut off the end of our buffer.

                    return true;
                } else {
                    // Resizing will require us to shift all the elements back.
                }
            }
        }


    private:
        int strt_indx;
        int end_indx;
        int buffer_size;
        T buffer[];

};
