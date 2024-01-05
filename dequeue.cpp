

template <typename T>
class dequeue {
    public:

        dequeue(T arr[], int size) {
            buffer_size = size;
            
        }

        int length() {
            return end_indx - strt_indx;
        }

        bool push(T val) {
            return false;
        }

        bool push_back(T val) {
            return false;
        }

        T pop() {
            return NULL;
        }

        T pop_back() {
            return NULL;
        }

        T peek() {
            return NULL;
        }

        T peek_back() {
            return NULL;
        }



    private:
        int strt_indx;
        int end_indx;
        int buffer_size;
        T buffer[];

};
