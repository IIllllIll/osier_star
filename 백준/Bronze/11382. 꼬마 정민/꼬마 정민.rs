use std::io;

fn main(){
    let mut s = String::new();

    io::stdin().read_line(&mut s).unwrap();

    let vec:Vec<i64> = s
        .as_mut_str()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();

    let a: i64 = vec[0];
    let b: i64 = vec[1];
    let c: i64 = vec[2];
    println!("{}",a+b+c);
}