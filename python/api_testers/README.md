# API Testers

This folder contains a small Flask test server for receiving itinerary data at `POST /api/itinerary`.

## File

- `url_ext.py`: starts a local Flask server on port `5000` and prints the received itinerary payload.

## Setup

From the `python` folder, activate the virtual environment and install dependencies with the same interpreter:

```powershell
.\.venv\Scripts\Activate.ps1
python -m pip install flask flask-cors
```

Use `python -m pip` instead of plain `pip` so packages are installed into the active virtual environment.

## Run

From the `python` folder:

```powershell
.\.venv\Scripts\python.exe .\api_testers\url_ext.py
```

The server runs at:

- `http://127.0.0.1:5000`

## Test Request

Example request:

```powershell
Invoke-RestMethod -Method Post `
  -Uri http://127.0.0.1:5000/api/itinerary `
  -ContentType "application/json" `
  -Body '{"itineraryId":"123","message":"test","pageUrl":"https://example.com","capturedAt":"2026-07-22T12:00:00Z"}'
```

## Notes

- CORS is enabled for local browser testing.
- This uses Flask's development server, so it is for testing only.
