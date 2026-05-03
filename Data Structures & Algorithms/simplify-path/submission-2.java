class Solution {
    public String simplifyPath(String path) {
        Stack<String> pending = new Stack<>();
        boolean isSlash = false;
        String cur = "";
        String res = "";
        for(int i = 0; i < path.length(); ++i) {
            if(path.charAt(i) == '/') {
                if(i > 0 && path.charAt(i - 1) != '/') {
                    if(cur.equals("..")) {
                        if(pending.size() > 0) {
                            pending.pop();
                        }
                    } else if(!cur.equals(".") && cur.length() != 0) {
                        pending.push(cur);
                    }
                }
                
                cur = "";
                continue;
            }

            cur += path.charAt(i);
            if (i == path.length() - 1) {
                if(cur.equals("..")) {
                    if(pending.size() > 0) {
                        pending.pop();
                    }
                } else if(!cur.equals(".")) {
                    pending.push(cur);
                }
            }
        }
        
        while(!pending.empty()) {
            res = "/" + pending.peek() + res;
            pending.pop();
        }
        if(res.length() == 0) return "/";
        return res;
    }
}