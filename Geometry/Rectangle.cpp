// to calculate the remind area after the truck maybe overlap the two triangles
// points is the leftlower and rightupper
struct Rect {
	int x1, y1, x2, y2;
	int area() { return (y2 - y1) * (x2 - x1); }
};

int intersect(Rect p, Rect q) {
	int xOverlap = max(0, min(p.x2, q.x2) - max(p.x1, q.x1));
	int yOverlap = max(0, min(p.y2, q.y2) - max(p.y1, q.y1));
	return xOverlap * yOverlap;
}

int main() {
	Rect a, b, t;  // billboards a, b, and the truck
	cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
	cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;
	cout << a.area() + b.area() - intersect(a, t) - intersect(b, t) << endl;
}

              *************************************************
   // to check the intersect between two rectangles
   bool intersect(vector<int> &s1, vector<int> &s2) {
       int bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
       int bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];

       // no overlap
       if (bl_a_x >= tr_b_x || tr_a_x <= bl_b_x || bl_a_y >= tr_b_y ||
           tr_a_y <= bl_b_y) {
           return false;
       } else {
           return true;
       }

       *************************************************
// calculate the area of intersection
               int inter_area(vector<int> s1, vector<int> s2) {
           int bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
           int bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];

           return ((min(tr_a_x, tr_b_x) - max(bl_a_x, bl_b_x)) *
                   (min(tr_a_y, tr_b_y) - max(bl_a_y, bl_b_y)));
       }
       ***************************************************

