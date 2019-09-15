class Solution:
    def decodeString(self, s: str) -> str:
        ans = "" 
        now = ""
        stack_num = []
        stack_str = []
        num = ""
        for i in range(len(s)):
            if s[i].isdigit():
                num = num + s[i]
                continue
            elif s[i] == '[': 
                stack_num.append(int(num))
                stack_str.append(now)
                num = ""
                now = ""
            elif s[i] == ']':
                mid_str = now
                times = stack_num[-1]
                del stack_num[-1]
                now = stack_str[-1] + times * mid_str
                del stack_str[-1]
            else:
                now = now + s[i]
            if(len(stack_num) == 0):
                ans = ans + now
                now = ""
        return ans
            