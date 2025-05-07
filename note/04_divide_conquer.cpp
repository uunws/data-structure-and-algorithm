// binary search : หาตำแหน่งของข้อมูลที่เราต้องการ
int bsearch(vector<int> &v, int k, int start, int stop) { // ข้อมูลsortedแล้ว
    if (start == stop) { // base case
        if (v[start] == k) {
            return start;
        } else {
            return -1;
        }
    }
    int m = (start+stop)/2; // or (start+stop) >> 1 (bitwise shift right)
    if (v[m] >= k) {
        return bsearch(v, k, start, m); // ค่าที่ได้มากไป->หาต่อในครึ่งหน้า
    } else {
        return bsearch(v, k, m+1, stop); // ค่าที่ได้น้อยไป -> หาต่อในครึ่งหลัง
    }
}

// merge sort : แบ่งครึ่ง(recur) sortในครึ่ง แล้วเอามาmergedกัน
void merge(vector<int> &v, int start, int m, int stop, vector<int> &tmp) {
    int bi = start; // index of B
    int ci = m+1; // index of C
    for (int i = start; i <= stop; i++) {
        if (ci > stop) { // C หมดแล้ว
            tmp[i] = v[bi++];
            continue;
        }
        if (bi > m) { // B หมดแล้ว
            tmp[i] = v[ci++]; 
            continue;
        }
        if (v[bi] < v[ci]) { // checkว่าตัวไหนน้อยกว่า ใส่ตัวนั้นก่อน
            tmp[i] = v[bi++];
        } else {
            tmp[i] = v[ci++];
        }
    }
    for (int i = start; i <= stop; i++) {
        v[i] = tmp[i] // copy คำตอบ จาก tmp กลับไปที่ v เหมือนเดิม
    }
}

// quick sort : use pivot
int partition(vector<int> &v, int start, int stop) {
    int pivot = v[start];

    int left = start - 1; // ก่อน start
    int right = stop + 1; // หลัง stop
    while (left < right) { // ถ้าไคว้ -> ไม่ต้องทำแล้ว
        do
            left = left + 1 // กระเถิบซ้ายไปเรื่อยๆ จนกระทั่งเจอตัวที่มากกว่า (ไม่ตรงตามกฎของpivot)
        until (A[left] >= pivot)
        do
            right = right - 1 // กระเถิบขวาไปเรื่อยๆ จนกระทั่งเจอตัวที่น้อยกว่า (ไม่ตรงตามกฎของpivot)
        until (A[right] <= pivot)
        if (left < right)
            swap(A[left],A[right]); // สลับ 2 ตัวนั้น
        else
        return right;
    }
    return right;
}
void quick_sort(vector<int> &v, int start, int stop) {
    if (start < stop) {
        int p = partiton(v, start, stop); // แบ่งฝั่ง : Hoare's algo
        quick_sort(v, start, p);
        quick_sort(v, p+1, stop);
    }
}

// a^n mod k
int mod(int a, int n, int k) {
    if (n == 1) {
        return a % k;
    }
    if (n % 2 == 0) {
        int tmp = mod(a, n/2, k);
        return (tmp*tmp) % k;
    } else {
        int tmp = mod(a, n/2, k);
        tmp = (tmp*tmp)%k;
        return (tmp * (a % k)) % k;
    }
}

// maximum sum of subarray : ช่วงติดกันที่ผลบวกมากสุด
// B[a][b] = B[a][k] + B[k+1][b]
int get_sum(vector<int> &prefix_sum, int l, int r) { // prefix_sum : ผลรวมสะสม
    if (l != 0) return prefix_sum[r] - prefix_sum[l-1];
    return prefix[r];
}

int mss(vector<int> &v, int start, int stop, vector<int> &prefix_sum) {
    if (start == stop) return v[start]; // base case
    int m = (start+stop)/2;

    int r1 = mss(v, start, m, prefix_sum);
    int r2 = mss(v, m+1, stop, prefix_sum);

    int max_sum_left = get_sum(prefix_sum, m, m);
    for (int i = start; i <= m-1; i++) { // start -> m-1
        max_sum_left = max(max_sum_left, get_sum(prefix_sum, i, m)); // value change in index x(left->x)
    }

    int max_sum_right = get_sum(prefix_sum, m+1, m+1);
    for (int i = m+2; i <= stop; i++) { // m+2 -> stop
        max_sum_right = max(max_sum_right, get_sum(prefix_sum, m+1, i)); // value change in index y(right->y)
    }

    int r3 = max_sum_left + max_sum_right;
    return max({r1, r2, r3});
}

// example code
int get_sum(vector<int> &prefix, int l, int r) {
    if (l==0) return prefix[r];
    return prefix[r] - prefix[l-1];
}

int mss(vector<int> &v, vector<int> &prefix, int start, int stop) {
    if (start == stop) return v[start];
    int m = (start+stop)/2;
    
    int r1 = mss(v, prefix, start, m);
    int r2 = mss(v, prefix, m+1, stop);

    int max_sum_left = get_sum(prefix, m, m);
    for (int i = start; i <= m-1; i++) {
        max_sum_left = max(max_sum_left, get_sum(prefix, i, m));
    }

    int max_sum_right = get_sum(prefix, m+1, m+1);
    for (int i = m+2; i <= stop; i++) {
        max_sum_right = max(max_sum_right, get_sum(prefix, m+1, i));
    }

    int r3 = max_sum_left + max_sum_right;
    return max({r1, r2, r3});
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v[0];
    vector<int> prefix(n);
    prefix[0] = v[0];
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        prefix[i] = prefix[i-1] + v[i];
    }
    cout << mss(v, prefix, 0, n-1);
}
// end example


// Strassen's

// closest pair