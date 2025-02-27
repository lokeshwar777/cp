import timeit

n=10**9

setup=f"l=[i for i in range({n})]"

slice_time = timeit.timeit("l[:]",setup=setup,number=1)

copy_time = timeit.timeit("l.copy()",setup=setup,number=1)

print(f"Time taken for slice in {slice_time}")
print(f"Time taken for copy in {copy_time}")