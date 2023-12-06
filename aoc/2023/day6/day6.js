
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
  let result = 0;

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
  for (let i = 0; i < time_values.length; i++) {
    let count = 0
    for (let j = 0; j < time_values[i]; j++) {
      let time_moving = time_values[i] - j;
      if (time_moving === time_values[i] || time_moving === 0) {
        continue;
      }
      if (time_moving * j > distance_values[i]) {
        count++;
      }
    }
    results[i] = count
  }
  console.log(results.reduce((acc, c_val) => acc * c_val, 1))

  //part 2
  let time_value = parseInt(time_values.join('', 10)) 
  let distance_value = parseInt(distance_values.join('', 10))
  let p2_result = 0;
  for (let i = 0; i < time_value; i++) {
    let time_moving = time_value - i;
    if (time_moving === time_value || time_moving === 0) {
      continue;
    }
    if (time_moving * i > distance_value) {
      p2_result++;
    }
  }
  console.log(p2_result)
})
