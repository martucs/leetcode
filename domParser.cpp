// Have the function 'CheckDOM(strParam : string) -> string' read
// the 'strParam' parameter being passed which will be a striing of html elements and plain text

// the elements that will be used are: b, i, em, div, p.

// your program should support 3 cases:
// 1. the string is a correct sequence of nested HTML elements, it should return the string 'true'
// 2. the string is almost correct: by changing a single tag you can make it corect, it should return first tag to change. 
//     Changing a tag does not include adding or removing a tag, or changing the opening into a closing tag and viceversa
// 3. the string is incorect (and to be correct it would require to change more than one element), 
//    your program should return the string 'false'

//EXAMPLES
// input: "<div><b><p>hello world</p></b></div>"
// output: true
// reason: the html is nested correctly

// input: "<div><i>hello</i>world</b>"
// output: "div"
// reason: if the first "<div>" element were changed, it would be okay (by "<b>")

// input: "</div><p></p><div>"
// output: false
// reason: the order of the opening and closing tags is incorrect, it would require more than one change to make it correct

// input: "< em>< /em>< em>< /em>< p>< /b>"
// output: p

// input: "< div>< p>< /p>< b>< p>< /div>"
// output: false