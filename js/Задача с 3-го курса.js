function dec_to_bin(dec) {
    bin = "";
    base = 2;
    while (dec > 0) {
        bin = dec % base + bin;
        dec = Math.floor(dec / base); 

    }
    if (bin == "") { 
        return "0";
    }
    return bin;
}


function comma_to_bin(number) {
    res = "";
    acc = 0
    while(acc != 16) {
        number *= 2;
        
        if (number > 10) {
            number = number % 10;
            res += "1"

        }
        else 
            res += "0";

        if (number == 10) {
            
            return res + "1";
        }
        acc++;
    }
    return res;
}
// вещественное десятичное число -> вещественное бинарное число
function float_to_bin(float) {
    string = float.toString().split('.');
    right = parseInt(string[0]);
    // left = parseFloat("0.".concat(string[1]));
    left = parseInt(string[1]);

    return dec_to_bin(right) + '.' + comma_to_bin(left);

}
float = 23.5
console.log(float_to_bin(float));