class Solution {
 public:
  bool isValidSerialization(string preorder) {
    if (preorder == "" || preorder == "#") return true;

    vector<int> nodes;
    int i = 0, len = preorder.length();
    while (i < len) {
      if (preorder[i] == '#') {
        nodes.push_back(0);
        i++;
      } else {
        while (i < len && preorder[i] >= '0' && preorder[i] <= '9') i++;
        nodes.push_back(1);
      }
      i++;
    }

    stack<int> S;
    for (int x : nodes) {
      if (x == 1)
        S.push(0);
      else {
        if (S.empty()) return false;
        if (S.top() == 0) {
          S.pop();
          S.push(1);
        } else {
          S.pop();
          while (!S.empty()) {
            if (S.top() == 0) {
              S.pop();
              S.push(1);
              break;
            } else {
              S.pop();
            }
          }
        }
      }
    }

    return S.empty();
  }
};

class Solution {
 public:
  bool isValidSerialization(string preorder) {
    if (preorder == "" || preorder == "#") return true;

    vector<int> nodes;
    int i = 0, len = preorder.length();
    while (i < len) {
      if (preorder[i] == '#') {
        nodes.push_back(0);
        i++;
      } else {
        while (i < len && preorder[i] >= '0' && preorder[i] <= '9') i++;
        nodes.push_back(1);
      }
      i++;
    }

    int depth = 0;
    for (i = 0; i < nodes.size() - 1; ++i) {
      if (nodes[i] == 0) {
        if (depth <= 0) return false;
        depth--;
      } else {
        depth++;
      }
    }
    return depth == 0 && nodes.back() == 0;
  }
};
