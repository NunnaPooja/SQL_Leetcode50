class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        #add elements into stack and remove whem u get a operation
        stack=[]
        ans=1
        for str in tokens:
            if str!= "*" and str!="/" and str!="+" and str!="-":
                stack.append(int(str))
            else:
                if len(stack)!=0:
                    temp1=stack[-1]
                    stack.pop()
                    if len(stack)!=0:
                        temp2=stack[-1]
                        stack.pop()
                    if str=="*":
                            stack.append(temp2*temp1)
                    elif str=="+":
                            stack.append(temp2+temp1)
                    elif str=="-":
                            stack.append(temp2-temp1)
                    elif str=="/":
                           stack.append(int(temp2/temp1))

        return stack[-1]


        