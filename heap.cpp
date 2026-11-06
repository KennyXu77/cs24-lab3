// heap.cpp
// Diba Mirza
#include <stdexcept>
#include "heap.h"
#include <iostream>
using std::cout;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
void Heap::percolateDown(int i) {
int size = vdata.size();
while (true) {
int left = 2 * i + 1;
int right = 2 * i + 2;
int smallest = i; 
if (left < size && vdata[left] < vdata[smallest]) {
smallest = left;
}
if (right < size && vdata[right] < vdata[smallest]) {
smallest = right;
}

if (smallest != i) {
std::swap(vdata[i], vdata[smallest]);
i = smallest;
} else {
break;
}
}
}
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
vdata.assign(start,end);
if(vdata.size()<=1){
  return;
}
int nonleaf=(vdata.size()-2)/2;
for(int i=nonleaf;i>=0;i--){
  percolateDown(i);
}
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
vdata.push_back(value);
int i=vdata.size()-1;
while (i > 0) {
int parents=(i-1)/2;
if(vdata[i]<vdata[parents]){
  std::swap(vdata[i],vdata[parents]);
  i=parents;
}else{
  break;
}
}
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
if (empty()) {
return;
}

vdata[0] = vdata.back();
 vdata.pop_back();
if (!vdata.empty()) {
percolateDown(0);
}
}

// Returns the minimum element in the heap
int Heap::top(){
if (empty()) {
throw std::out_of_range("Heap is empty");
}
return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
return vdata.empty();
}
    