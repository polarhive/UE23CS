import serial
import asyncio
from fastapi import FastAPI, WebSocket
from fastapi.responses import HTMLResponse
import uvicorn

app = FastAPI()

# Connect to Arduino (update port if needed)
arduino = serial.Serial('/dev/ttyACM0', 9600)

@app.get("/")
async def index():
    return HTMLResponse(open("index.html").read())

@app.websocket("/ws")
async def websocket_endpoint(websocket: WebSocket):
    await websocket.accept()
    try:
        while True:
            data = arduino.readline().decode("utf-8").strip()
            
            # Parse key-value pairs
            if data.startswith("[SENSOR]:"):
                value = data.replace("[SENSOR]:", "").strip()
                await websocket.send_json({"type": "sensor", "value": value})
            elif data.startswith("[INFO]:"):
                message = data.replace("[INFO]:", "").strip()
                await websocket.send_json({"type": "info", "message": message})
            elif data.startswith("[ALARM]:"):
                message = data.replace("[ALARM]:", "").strip()
                await websocket.send_json({"type": "alarm", "message": message})
            
            await asyncio.sleep(0.1)
    except Exception as e:
        print(f"WebSocket error: {e}")
        await websocket.close()
    finally:
        arduino.close()

if __name__ == "__main__":
    uvicorn.run(app, host="0.0.0.0", port=8000)
