import os

#os.system("pip install pyinstaller")
os.system("pyinstaller pbrain-gomoku-ai --name pbrain-gomoku-ai.exe --onefile")
os.system('copy .\\dist\\pbrain-gomoku-ai.exe .')
