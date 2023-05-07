#include <iostream>
#include <vector>

using namespace std;

// Quick Sort
void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int p = i + 1;
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}

// Heap Sort
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Shell Sort
void shell_sort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Tree Sort
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void insert(TreeNode*& root, int val) {
    if (root == NULL) {
        root = new TreeNode(val);
    }
    else if (val < root->val) {
        insert(root->left, val);
    }
    else {
        insert(root->right, val);
    }
}

void inorder(TreeNode* root, vector<int>& res) {
    if (root) {
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
}

void tree_sort(vector<int>& arr) {
    TreeNode* root = NULL;
    for (int i = 0; i < arr.size(); i++) {
        insert(root, arr[i]);
    }
    arr.clear();
    inorder(root, arr);
}

// Main function
int main() {
    vector<int> arr = {10, 80, 30, 90, 40, 50, 70};

    // Quick Sort
    vector<int> arr1 = arr;
    quick_sort(arr1, 0, arr1.size() - 1);
    cout << "Quick Sort:\n";
    for (int i = 0; i < arr1.size(); i++) {
    cout << arr1[i] << " ";
}
cout << endl;

// Heap Sort
vector<int> arr2 = arr;
heap_sort(arr2);
cout << "Heap Sort:\n";
for (int i = 0; i < arr2.size(); i++) {
    cout << arr2[i] << " ";
}
cout << endl;

// Shell Sort
vector<int> arr3 = arr;
shell_sort(arr3);
cout << "Shell Sort:\n";
for (int i = 0; i < arr3.size(); i++) {
    cout << arr3[i] << " ";
}
cout << endl;

// Tree Sort
vector<int> arr4 = arr;
tree_sort(arr4);
cout << "Tree Sort:\n";
for (int i = 0; i < arr4.size(); i++) {
    cout << arr4[i] << " ";
}
cout << endl;

return 0;
}