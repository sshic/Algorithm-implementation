#Find the k'th smallest element in the union of two sorted arrays
#time complexity:log(k)

def findKth():
    k=5
    i=k/2
    j=k/2
    step=k/4
    while step>0:
        if a[i-1]<b[j-1]:
            i=i+step
            j=j-step
        else:
            i=i-step
            j=j+step		
        step/=2
    if k%2==0:
        print "xx"
        if a[i-1]>b[j-1]:
            print a[i-1]
        else:
            print b[j-1]
    else:
        print "yy"
        print i,j
        if a[i]>b[j]:
            print b[j]
        else:
            print a[i]
	
if __name__=='__main__':
    a=[1,3,4,5,8]
    b=[2,6,7,9,10]    
    findKth()