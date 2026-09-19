# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: ListNode | None) -> ListNode | None:
        arr = []
        cur = head

        while cur:
            arr.append(cur.val)
            cur = cur.next
        
        arr.sort()

        dummy = ListNode(0)
        temp = dummy

        for i in arr:
            temp.next = ListNode(i)
            temp = temp.next
    
        return dummy.next