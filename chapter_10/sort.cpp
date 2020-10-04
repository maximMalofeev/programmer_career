#include <algorithm>
#include <iostream>
#include <vector>

void bubble_sort(std::vector<int>& arr) {
  for (int i = 1; i < arr.size(); i++) {
    for (int j = 1; j < arr.size(); j++) {
      if (arr[j - 1] > arr[j]) {
        std::swap(arr[j], arr[j - 1]);
      }
    }
  }
}

void choose_sort(std::vector<int>& arr) {
  for (int i = 0; i < arr.size(); i++) {
    int min_index = i;
    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[j] < arr[min_index]) {
        min_index = j;
      }
    }
    std::swap(arr[i], arr[min_index]);
  }
}

std::vector<int>& merge_sort_rec(std::vector<int>& arr) {
  if(arr.size() <= 1) {
    return arr;
  }

  int mid = arr.size() / 2;

  std::vector<int> arr_l{arr.begin(), arr.begin() + mid};
  std::vector<int> arr_r{arr.begin() + mid, arr.end()};
  merge_sort_rec(arr_l);
  merge_sort_rec(arr_r);

  int l = 0;
  int r = 0;
  int i = 0;
  while(l < arr_l.size() && r < arr_r.size()) {
    if(arr_l[l] < arr_r[r]) {
      arr[i] = arr_l[l];
      i++;
      l++;
    }else {
      arr[i] = arr_r[r];
      i++;
      r++;
    }
  }

  while(l < arr_l.size()) {
    arr[i] = arr_l[l];
    i++;
    l++;
  }

  while(r < arr_r.size()) {
    arr[i] = arr_r[r];
    i++;
    r++;
  }

  return arr;
}

void merge_sort(std::vector<int>& arr) {
  merge_sort_rec(arr);
}

// 0 4 1 3
void quick_sort(std::vector<int>& arr, int left, int right) {
  int pivot = arr[(right + left) / 2];

  int l = left;
  int r = right;
  while(l <= r) {
    while(arr[l] < pivot){
      l++;
    }
    while(arr[r] > pivot) {
      r--;
    }

    if(l <= r) {
      std::swap(arr[l], arr[r]);
      l++;
      r--;
    }
  }
  if(r > left){
    quick_sort(arr, left, r);
  }
  if(l < right) {
    quick_sort(arr, l, right);
  }
}

void quick_sort(std::vector<int>& arr) {
  quick_sort(arr, 0, arr.size() - 1);
}

int main(int argc, char const* argv[]) {
  std::vector<int> arr{2, 5, 4, 1, 2, 7, 6, 3};
  // std::vector<int> arr{2, 5, 4, 1};

  // bubble_sort(arr);
  // choose_sort(arr);
  // merge_sort(arr);
  quick_sort(arr);

  for (auto i : arr) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}
