#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
const double PI = 2.0 * acos(0.0);
const double EPSILON = 1e-10;
struct vector2
{
    double x, y;
    explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_){}
    bool operator==(const vector2& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
    bool operator < (const vector2& rhs) const{
        return x != rhs.x ? x < rhs.x : y < rhs.y;
    }
    vector2 operator + (const vector2& rhs) const{
        return vector2(x + rhs.x, y + rhs.y);
    }
    vector2 operator - (const vector2& rhs) const{
        return vector2(x - rhs.x, y - rhs.y);
    }
    vector2 operator * (double rhs) const{
        return vector2(x * rhs, y * rhs);
    }
    double norm() const {return hypot(x, y); }
 
    vector2 normalize() const {
        return vector2(x / norm(), y / norm());
    }
     double polar() const {
         return fmod(atan2(y,x) + 2* PI, 2*PI);
     }
     double dot(const vector2& rhs) const{
         return x * rhs.x - y * rhs.y;
     }
    double cross(const vector2& rhs) const {
        return x * rhs.y - y * rhs.x;
    }
    vector2 project(const vector2& rhs) const {
        vector2 r = rhs.normalize();
        return r * r.dot(*this);
    }
};
 
double ccw(vector2 a, vector2 b){
    return a.cross(b);
}
double ccw(vector2 p, vector2 a, vector2 b){
    return ccw(a-p, b-p);
}
bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x){
    double det = (b - a).cross(d - c);
    if(fabs(det) < EPSILON) return false;
 
    x = a + (b - a) * ((c - a).cross(d - c) / det);
    return true;
}
 
bool parallelSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p){
    if(b < a) swap(a, b);
    if(d < c) swap(c, d);
 
    if(ccw(a, b, c) != 0 || b < c || d < a) return false;
 
    if(a < c) p = c; else p = a;
    return true;
}
 
bool inBoundingRectangle(vector2 p, vector2 a, vector2 b){
    if( b < a) swap(a, b);
    return p == a || p == b || (a < p && p < b);
}
bool segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p){
    if(!lineIntersection(a, b, c, d, p))
        return parallelSegments(a, b, c, d, p);
 
    return inBoundingRectangle(p, a, b) && inBoundingRectangle( p , c, d);
}
typedef vector<vector2> polygon;
 
void swap(int a, int b){
    int temp = b;
    b = a;
    a = temp;
}
void swap(vector2 a, vector2 b){
    vector2 temp = b;
    b = a;
    a = temp;
}


double capArea(const polygon& A, const polygon& B);
int main(){
    freopen("input.txt","r",stdin);
    setbuf(stdout, NULL);
 
    int TC; cin>>TC;
 
    while(TC--){
        int x1, y1, x2, y2;
        int N;
        cin>>x1>>y1>>x2>>y2>>N;
        polygon trea, rect;
        int buf1, buf2;
        for(int i = 0; i < N; i++){
            cin>>buf1>>buf2;
            trea.push_back(vector2(buf1, buf2));
        }
        if(x1 > x2) swap(x1, x2);

        if(y1 > y2) swap(y1, y2);
        
        rect.push_back(vector2(x1, y1));
        rect.push_back(vector2(x2, y1));
        rect.push_back(vector2(x2, y2));
        rect.push_back(vector2(x1, y1));
 
        capArea(trea, rect);
    }
 
    
    return 0;
}
 
// double capArea(const polygon& A, const polygon& B){
    
//      int n = A.size(), m = B.size();

//      polygon C;
//      for(int i = 0; i < n ; i++){
//          for(int j = 0 ; j < m; j++){
//               vector2 c;
//               if(segmentIntersection(A[i], A[(i+1)%n], B[j],B[(j+1)%m], c ) ) {
//                   C.push_back(c);
//               }
//           }
//      }
//      int l = C.size();
//      vector<double> event;

//      for(int i = 0; i < n; i++){
//         event.push_back(A[i].x);
//      }
//      for(int i = 0; i < m; i++){
//         event.push_back(B[i].x);
//      }
//      for(int i = 0; i < l; i++){
//         event.push_back(C[i].x);
//      }

//      sort(event.begin(), event.end());
//      event.erase(unique(event.begin(), event.end()),event.end());
//      // for(int i = 0; i < event.size(); i++){
//      //    cout<<event[i]<<" ";
//      // }
//      // cout<<event.size()<<endl;
//      // cout<<endl;
//      vector<pair<double, int> >h1, h2;
//      for(int i = 0; i < n; i++){
//         vector2 c;
//         if(segmentIntersection(A[i], A[(i+1)%n],vector2(event[0], -1.0), vector2(event[0], 101.0),c)){
//             h2.push_back(make_pair(c.y,1));
//         }
//      }
//      for(int i = 0; i < m; i++){
//         vector2 c;
//         if(segmentIntersection(B[i], B[(i+1)%m], vector2(event[0], -1.0), vector2(event[0], 101.0),c)){
//             h2.push_back(make_pair(c.y,2));
//         }
//      }

//      sort(h2.begin(), h2.end());
//      vector<pair<double, int> >::iterator it;
//      for(it = h2.begin(); it < h2.end();){
//         if(abs((it+1)->first - (it)->first ) < EPSILON){
//             it = h2.erase(it);
//             // it->second = 3;
//         }
//         else{
//             it++;
//         }
//      }

//      for(int vent = 0; vent < event.size() - 1; vent++){
//          h1.clear(); 
//          h1 = h2;
//          h2.clear();
//          for(int i = 0; i < n; i++){
//               vector2 c;
//               if(segmentIntersection(A[i], A[(i+1)%n],vector2(event[vent + 1], -1.0), vector2(event[vent + 1], 101.0),c)){
//                   h2.push_back(make_pair(c.y,1));
//               }
//          }
//          for(int i = 0; i < m; i++){
//               vector2 c;
//               if(segmentIntersection(B[i], B[(i+1)%n],vector2(event[vent + 1], -1.0), vector2(event[vent + 1], 101.0),c)){
//                   h2.push_back(make_pair(c.y,2));
//               }
//          }
//          sort(h2.begin(), h2.end());
//          for(it = h2.begin(); it < h2.end();){
//             if(abs((it+1)->first - (it)->first ) < EPSILON){
//                 it = h2.erase(it);
//             }
//             else{
//                 it++;
//             }
//          }
         
//          // cout<<h1.size()<<"   "<<h2.size()<<endl;
//          for(int i = 0; i < h1.size(); i++){
//             cout<<h1[i].second<<" ";
//          }
//          cout<<endl;
//      }
//      cout<<endl<<endl;
// }

double capArea(const polygon& A, const polygon& B){

    int n = A.size(), m = B.size();
    polygon C;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m ; j++){
            vector2 c;
            if(segmentIntersection(A[i],A[(i+1)%n], B[j], B[(j+1)%m], c)){
                C.push_back(c);
            }
        }
    }

    int l = C.size();

    vector<pair<double, vector<pair<double, int> > > > event;

    int xx;
    for(int i = 0; i < n; i++){
        xx = -1;
        for(int j = 0; j < event.size(); j++){
            if(A[i].x == event[j].first){
                event[j].second.push_back(make_pair(A[i].y,1));
                xx = 1;
                break;
            }
        }
        if(xx == -1){
            vector<pair<double, int> > AAA;
            AAA.push_back(make_pair(A[i].y,1));
            event.push_back(make_pair(A[i].x, AAA));
        }
    }

    for(int i = 0; i < m; i++){
        xx = -1;
        for(int j = 0; j < event.size(); j++){
            if(B[i].x == event[j].first){
                event[j].second.push_back(make_pair(B[i].y,2));
                xx = 1;
                break;
            }
        }
        if(xx == -1){
            vector<pair<double, int> > AAA;
            AAA.push_back(make_pair(B[i].y,2));
            event.push_back(make_pair(B[i].x, AAA));
        }
    }
    
    for(int i = 0; i < n; i++){
        xx = -1;
        for(int j = 0; j < event.size(); j++){
            if(A[i].x == event[j].first){
                event[j].second.push_back(make_pair(A[i].y,1));
                xx = 1;
                break;
            }
        }
        if(xx == -1){
            vector<pair<double, int> > AAA;
            AAA.push_back(make_pair(A[i].y,1));
            event.push_back(make_pair(A[i].x, AAA));
        }
    }



}   