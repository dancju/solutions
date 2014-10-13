use std::collections::HashMap;
use std::io::stdin;

struct Node {
    children: HashMap<char, Box<Node>>,
    size: usize,
}

impl Node {
    fn new() -> Node {
        Node {
            children: HashMap::new(),
            size: 0,
        }
    }
    fn insert(&mut self, s: &mut Iterator<Item = char>) -> () {
        self.size += 1;
        match s.next() {
            Some(c) => {
                self.children
                    .entry(c)
                    .or_insert(Box::new(Node::new()))
                    .insert(s);
            }
            None => {}
        }
    }
    fn bazinga(&self, is_root: bool) -> usize {
        if self.size <= 1 {
            return 0;
        }
        let mut res = 0;
        for i in self.children.iter() {
            res += i.1.bazinga(false);
        }
        if !is_root && self.size - res >= 2 {
            res += 2;
        }
        return res;
    }
}

struct Tire {
    root: Node,
}

impl Tire {
    fn new() -> Tire {
        Tire { root: Node::new() }
    }
    fn insert(&mut self, s: &mut Iterator<Item = char>) -> () {
        self.root.insert(s);
    }
    fn bazinga(&self) -> usize {
        self.root.bazinga(true)
    }
}

fn next<T>() -> T
where
    T: std::str::FromStr,
    <T as std::str::FromStr>::Err: std::fmt::Debug,
{
    let mut x: String = "".to_string();
    stdin().read_line(&mut x).unwrap();
    x.trim().parse::<T>().unwrap()
}

fn main0() -> () {
    let mut n: u32 = next();
    let mut t = Tire::new();
    while n != 0 {
        let mut w: String = "".to_string();
        stdin().read_line(&mut w).unwrap();
        t.insert(&mut w.trim().chars().rev());
        n -= 1;
    }
    println!("{}", t.bazinga());
}

fn main() -> () {
    let n_case: u32 = next();
    for i_case in 1..1 + n_case {
        print!("Case #{}: ", i_case);
        main0();
    }
}
