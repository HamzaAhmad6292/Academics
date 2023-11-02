from web3 import Web3

# Connect to the Polygon network
w3 = Web3(Web3.HTTPProvider('https://rpc-mainnet.maticvigil.com'))

def get_wallet_balance(wallet_address):
    balance = w3.eth.get_balance(wallet_address)
    return w3.fromWei(balance, 'ether')

# Replace '0x9B6B92D448D9837E64211574A89a690BDEE61023' with your wallet address
wallet_address = '0x9B6B92D448D9837E64211574A89a690BDEE61023'

balance = get_wallet_balance(wallet_address)
print(f'Wallet balance: {balance} MATIC')
