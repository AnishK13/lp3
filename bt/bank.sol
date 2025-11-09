pragma solidity ^0.8.0;

contract CustomerBankAccount {
    address public owner;
    mapping(address => uint256) private balances;

    event Deposit(address indexed customer, uint256 amount);
    event Withdrawal(address indexed customer, uint256 amount);

    constructor() {
        owner = msg.sender;
    }

    function deposit() external payable {
        require(msg.value > 0, "Deposit amount must be greater than 0");
        balances[msg.sender] += msg.value;
        emit Deposit(msg.sender, msg.value);
    }

    function withdraw(uint256 amount) external {
        require(amount > 0, "Withdrawal amount must be greater than 0");
        require(balances[msg.sender] >= amount, "Insufficient balance");

        balances[msg.sender] -= amount;
        payable(msg.sender).transfer(amount);

        emit Withdrawal(msg.sender, amount);
    }

    function getBalance() external view returns (uint256) {
        return balances[msg.sender];
    }
    fallback() external payable {
        revert("Use deposit() instead");
    }

    receive() external payable {
        revert("Use deposit() instead");
    }
}