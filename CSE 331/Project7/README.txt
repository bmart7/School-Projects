Project 7


Name: Brian Martin

Time to Complete: 3 hours

Feedback: I was having trouble with my quadradic_probe function because at first I was re-evaluating the hash_function
          like:
          bucket = (self.hash_function(key) + i * i) % self.capacity
          instead of:
          bucket = (bucket + i * i) % self.capacity
          Other than that the project was pretty straightforward


Sources Used: Zybooks, Class Notes
