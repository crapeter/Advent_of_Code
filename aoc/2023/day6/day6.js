
const fs = require('fs')

const filePath = 'input.txt'

fs.readFile(filePath, 'utf8', (err, data) => {
  if (err) {
    console.error(`Error reading file: ${err}`)
    return
  }

  let time_values = []
  let distance_values = []
  let results = Array(time_values.length).fill(0)

  const lines = data.trim().split('\n')
  const regex = /\d+/g;

  for (const line of lines) {
    if (line.includes("Time")) {
      const nums = line.match(regex)
      if (nums) {
        const numbers = nums.map(Number)
        time_values = time_values.concat(numbers);
      }
    } else {
      const nums = line.match(regex)
      if (nums) {
        const numbers = nums.map(Number)
        distance_values = distance_values.concat(numbers);
      }
    }
  }

  //part 1
  let p1_result = 0;
  time_values.forEach((time, index) => { let count = get_results(time, distance_values[index]); results[index] = count })
  p1_result = results.reduce((acc, c_val) => acc * c_val, 1)
  console.log(p1_result)

  //part 2
  let time_value = parseInt(time_values.join('', 10)) 
  let distance_value = parseInt(distance_values.join('', 10))
  let p2_result = get_results(time_value, distance_value);
  console.log(p2_result)
})

function get_results(time, distance) {
  let result = 0;
  for (let i = 0; i < time; i++)
    if ((time - i) * i > distance)
      result++;
  return result
}
