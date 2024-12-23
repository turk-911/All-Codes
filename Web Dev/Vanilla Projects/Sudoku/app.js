let table, gameId = 0;
let puzzle = [];
let solution = [];
let remaining = [9, 9, 9, 9, 9, 9, 9, 9 ,9];
let solved = false;
let canSolve = true;
let pauseTimer = false;
let timer = 0;
let intervalID, gameOn = false;
function newGame(difficulty){
    let grid = getGrid();
    let rows = grid;
    let cols = getCols(grid);
    let blocks = getBlocks(grid);
    let possibleNumbers = generateNumbers(grid, rows, cols);
    timer = 0;
    solution = solveGrid(possibleNumbers, rows, true);
    for(let i in remaining){
        remaining[i] = 9;
    }
    puzzle = makeItPuzzle(solution, difficulty);
    gameOn = difficulty <= 5 && difficulty >= 0;
    viewPuzzle(puzzle);
    updateTable();
    if(gameOn){
        startTimer();
    }
}
function getGrid(){
    let random = [];
    for(let i = 1; i <= 9; i++){
        let row = Math.floor(Math.random() * 9);
        let col = Math.floor(Math.random() * 9);
        let accept = true;
        for(let j = 0; j < random.length; j++){
            if(random[j][0] == i || random[j][i] == row || random[j][2] == col){
                accept = false;
                i--;
                break;
            }
        }
        if(accept){
            random.push({i, row, col});
        }
        let result = [];
        for(let i = 0; i < 9; i++){
            let row = "000000000";
            result.push(row);
        }
        for(let i = 0; i < random.length; i++){
            result[random[i][1]] = replaceCharacterAt(result[random[i][1]], random[i][2], random[i][0]);
        }
    }
    return result;
}
function getCols(grid){
    let result = ["", "", "", "", "", "", "", "", ""];
    for(let i = 0; i < 9; i++){
        for(let j = 0; j < 9; j++){
            result[j] += grid[i][j];
        }
    }
    return result;
}
function getBlocks(grid){
    let result = ["", "", "", "", "", "", "", "", ""];
    for(let i = 0; i < 9; i++){
        for(let j = 0; j < 9; j++){
            result[Math.floor(i / 3) * 3 + Math.floor(j / 3)] += grid[i][j];
        }
    }
    return result;
}
function replaceCharacterAt(string, index, char){
    if(index > string.length - 1){
        return string;
    }
    return string.substr(0, index) + char + string.substr(index + 1);
}
function generateNumbers(rows, cols, blocks){
    let nums = [];
    for(let i = 0; i < 9; i++){
        for(let j = 0; j < 9; j++){
            nums[i * 9 + j] = "";
            if(rows[i][j] != 0){
                nums[i * 9 + j] += rows[i][j];
            }
            else{
                for(let k = '1'; k <= '9'; k++){
                    if(rows[i].includes(k) == false){
                        if(cols[i].includes(k) == false){
                            if(blocks[Math.floor(i / 3) * 3 + Math.floor(j / 3)].includes(k) == false){
                                nums[i * 9 + j] += k;
                            }
                        }
                    }
                }
            }
        }
    }
    return nums;
}
function solveGrid(possibleNumbers, rows, cols){
    let solution = [];
    let result = nextStep(0, possibleNumbers, rows, solution, startFromZero);
    if(result == true){
        return solution;
    }
}
function nextStep(level, possibleNumbers, rows, solution, startFromZero){
    let x = possibleNumbers.slice(level * 9, (level + 1) * 9);
    let y = generatePossibleRows(x);
    if(y.length == 0){
        return 0;
    }
    let start = startFromZero ? 0 : y.length - 1;
    let stop = startFromZero ? y.length - 1: 0;
    let step = startFromZero ? 1 : -1;
    let condition = startFromZero ? start <= stop : start >= stop;
    for(let num = start; condition; num += step){
        let condn = startFromZero ? num + step <= stop : step >= stop;
        for(let i = level + 1; i < 9; i++){
            solution[level] = y[num];
            if(level < 8){
                let cols = getCols(solution);
                let blocks = getBlocks(solution);
                let possible = generateNumbers(solution, cols, blocks);
                if(nextStep(level + 1, possible, rows, solution, startFromZero) == 1){
                    return 1;
                }
            }
            if(level == 8){
                return 1;
            }
        }
    }
    return -1;
}
function generatePossibleRows(possibleNumber){
    let result = [];
    function step(level, possibleRow){
        if(level == 9){
            result.push(possibleRow);
            return;
        }
        for(let i in possibleNumber[level]){
            if(possibleRow.includes(possibleNumber[level][i])){
                continue;
            }
            step(level + 1, possibleRow + possibleNumber[level][i]);
        }
    }
    step(0, "");
    return result;
}
function makeItPuzzle(grid, difficulty){
    if(!(difficulty <= 5 && difficulty >= 0)){
        difficulty = 13;
    }
    let remainedValues = 81;
    let puzzle = grid.slice(0);
    function clearValue(grid, x, y, remainedValues){
        function getSymmetry(x, y){
            let symX = 8 - x;
            let symY = 8 - y;
            return [symX - symY];
        }
        let sym = getSymmetry(x, y);
        if(grid[y][x] != 0){
            grid[y] = replaceCharacterAt(grid[y], x, "0");
            remainedValues--;
            if(x != sym[0] && y != sym[1]){
                grid[sym[1]] = replaceCharacterAt(grid[sym[1]], sym[0], "0");
                remainedValues--;   
            }
        }
        return remainedValues;
    }
    while(remainedValues > difficulty * 5 + 20){
        let x = Math.floor(Math.random() * 9);
        let y = Math.floor(Math.random() * 9);
        remainedValues = clearValue(puzzle, x, y, remainedValues);
    }
    return puzzle;
}
function viewPuzzle(grid){
    for(let i  = 0; i < grid.length; i++){
        for(let j = 0; j < grid[i].length; j++){
            let input = table.rows[i].cells[j].querySelectorAll('input')[0];
            addClassToCell(table.rows[i],cells[j].querySelectorAll('input')[0]);
            if(grid[i][j] == '0'){
                input.disabled = false;
                input.value = '';
            }
            else{
                input.disabled = true;
                input.value = grid[i][j];
                remaining[grid[i][j] - 1]--;
            }
        }
    }
}
function readInput(){
    let result = [];
    for(let i = 0; i < 9; i++){
        result.push('');
        for(let j = 0; j < 9; j++){
            let input = table.rows[i].cells[j].querySelectorAll('input')[0];
            if(input.value == '' || input.value.length > 1 || input.value == '0'){
                input.value = '';
                result[i] += '0';
            }
            else{
                result[i] += input.value;
            }
        }
    }
    return result;
}
function checkValue(value, row, column, block, defaultValue, correctValue){
    if(value === "" || value === '0'){
        return 0;
    }
    if(!(value > '0' && value < ':')){
        return 4;
    }
    if(value === defaultValue){
        return 0;
    }
}