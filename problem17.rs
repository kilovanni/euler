///
/// Computes how many letters there would be if we write out all the numbers
/// from 1 to 1000 in British Egnlish.
///
fn main() {
    let zero_to_ten = [0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3];
    let eleven_to_nineteen = [0, 6, 6, 8, 8, 7, 7, 9, 8, 8];
    let twenty_to_ninety = [0, 0, 6, 6, 5, 5, 5, 7, 6, 6];
    let hundred = 7;
    let thousand = 8;
    let and = 3;

    let mut x: uint;
    let mut remainder: uint;
    let mut wholes: uint;
    let mut sum: uint = zero_to_ten[1] + thousand;
    
    for i in range(1, 1000) {
        x = i;
        
        if x > 99 {
            wholes = x / 100u;
            if x % 100 != 0 {
                sum += zero_to_ten[wholes] + hundred + and
            } else {
                sum += zero_to_ten[wholes] + hundred; 
                continue;
            }
            x -= wholes * 100;
        }

        if x >= 10 && x < 20 {
            remainder = x % 10;

            match remainder {
                1...9   => sum += eleven_to_nineteen[remainder],
                0       => sum += zero_to_ten[10],
                _       => panic!("Something went VERY wrong."),
            }
        continue;
        }

        wholes = x / 10u;
        sum += twenty_to_ninety[wholes];
        x -= wholes * 10;

        sum += zero_to_ten[x];
    }

    println!("The number of letters is {}", sum);
}

