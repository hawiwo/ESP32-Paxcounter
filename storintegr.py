import json
import requests

Application="hawiwo-paxcounter-02"
APIKey = "YMZZBA6HRQB5FLJQQBH5BIFYMAH2POT3U4F2HWY"
Fields = "up.uplink_message.decoded_payload,up.uplink_message.frm_payload"
NumberOfRecords = 30
URL = "https://eu1.cloud.thethings.network/api/v3/as/applications/" + Application + "/packages/storage/uplink_message?order=-received_at&limit=" + str(NumberOfRecords) + "&field_mask=" + Fields
Header = { "Accept": "text/event-stream", "Authorization": "Bearer " + APIKey }

print("\n\nFetching from data storage...\n")

r = requests.get(URL, headers = Header)
JSON = "{\"data\": [" + r.text.replace("\n\n", ",")[:-1] + "]}";

print("URL: {}\n".format(r.url))
print("Status: {}\n".format(r.status_code))
print("Response: {}\n".format(r.text))
print("JSON: ")
print(json.dumps(json.loads(JSON), indent = 4))
print()
