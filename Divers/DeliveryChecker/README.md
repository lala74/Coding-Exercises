# Delivery Checker <!-- omit in toc -->

[Link](https://dashdoc.slab.com/public/developer-technical-test-dashdoc-1jr1oph7)

## Problem
The goal of this test is to create a program that will take a list of deliveries and a path, determine if the given path is acceptable to complete all deliveries, and if it is, return a list of steps to give to the truck driver.
The program can be written in Python or Javascript (or TypeScript), and it should be called either with python deliverychecker.py or node deliverychecker.js.
Expect to spend between one and three hours on this interview.

**Input**  
The input will be standard input with 2 parameters containing a list of comma-separated numbers.

Example:  python deliverychecker.py "[[1,2],[3,4]]" "[1,3,2,4,5]"

The first input is actually a JSON encoded list of tuples, describing deliveries to be done, where each number represents the id of an address.

So for instance in this example ([[1,2],[3,4]]) there are 2 deliveries: pickup at 1, dropoff at 2 and pickup at 3, dropoff at 4.

The second input is the path of the truck, where each number in the list is an address visited by the truck.

We suppose that both the path and the deliveries will not visit the same address twice.

```bash
python deliverychecker.py "[[1,3],[2,5]]" "[1,2,3,4,5]"
python deliverychecker.py "[[1,2],[3,4]]" "[1,2,4]"
python deliverychecker.py "[[1,3],[2,4]]" "[1,4,2,3]"
```

**Output**  
return the json of the steps in case of success, in this shape:
```json
{
  "status": "success", 
  "steps": [
     {"address": 12, "action": "pickup"}, 
     {"address": 3, "action": "dropoff"},
     {"address": 4, "action": null}, 
     {"address": 6, "action": "pickup"},
     {"address": 9, "action": "dropoff"}
  ]
}
```
there are 3 possible actions in a step: "pickup",  "dropoff", and null

in case of error print to stdout a json with a status field (success, error) and an error_code and error_message field

if some deliveries are not picked up and dropped off, print an error to stdout with code delivery_address_not_in_path

else if some dropoffs are before the associated pickup, print an error to stdout with code delivery_dropoff_before_pickup

make it easy to know what's wrong with the submitted path by using good error messages


```json
{
  "status": "success",
  "steps": [
    {
      "address": 1,
      "action": "pickup"
    },
    {
      "address": 2,
      "action": "pickup"
    },
    {
      "address": 3,
      "action": "dropoff"
    },
    {
      "address": 4,
      "action": null
    },
    {
      "address": 5,
      "action": "dropoff"
    }
  ]
}
{
  "status": "error",
  "error_code": "delivery_address_not_in_path",
  "error_message": "..."
}
{
  "status": "error",
  "error_code": "delivery_dropoff_before_pickup",
  "error_message": "..."
}
```
